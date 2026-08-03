#include <iostream>
using namespace std;

bool distinct(int z) {
    int a = z % 10;          // Fixed: changed 'a%10' to 'z%10'
    int b = (z / 10) % 10;
    int c = (z / 100) % 10;
    int d = (z / 1000) % 10;
    return (a != b && a != c && a != d && b != c && b != d && c != d);
}

int main() {
    int x; 
    cin >> x;
    while (true) {
        x++;
        if (distinct(x)) {
            cout << x << endl;
            return 0; 
        }
    }    
}