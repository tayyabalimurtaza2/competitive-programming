#include <iostream>
using namespace std;

int main() {
    string s; 
    cin >> s;
    
    int a = 0, b = 0; 
    bool match = false;
    
    for (size_t i = 0; i < s.size(); i += 2) {
        // 1. Correctly convert character digits to integers
        if (s[i] == 'A') {
            a += s[i+1] - '0';
        } else {
            b += s[i+1] - '0';
        }
        
        // 2. Check if they tied at 10-10
        if (a == 10 && b == 10) {
            match = true;
        }
        
        // 3. Evaluate win conditions based on the rule active
        if (match) {
            if (a - b >= 2) {
                cout << "A";
                return 0;
            } else if (b - a >= 2) {
                cout << "B"; 
                return 0;
            }
        } else {
            // Normal win condition: must reach 11 points
            if (a >= 11) {
                cout << "A";
                return 0;
            } else if (b >= 11) {
                cout << "B";
                return 0;
            }
        }
    }
    return 0;
}