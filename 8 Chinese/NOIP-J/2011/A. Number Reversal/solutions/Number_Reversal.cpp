#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool neg = false;

    // Check for negative number
    if (s[0] == '-') {
        neg = true;
        s.erase(0, 1);      // Remove '-'
    }

    // Reverse the digits
    reverse(s.begin(), s.end());

    // Skip only the leading zeros
    int i = 0;
    while (i < s.size() && s[i] == '0')
        i++;

    // If all digits were zero
    if (i == s.size()) {
        cout << 0;
        return 0;
    }

    // Print the sign
    if (neg)
        cout << "-";

    // Print the remaining digits
    while (i < s.size()) {
        cout << s[i];
        i++;
    }
    return 0;
}