#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        int c = 0;            // count how many times 2 divides n
        while (n % 2 == 0) { n /= 2; c++; }
        if (c == 0)      cout << "Odd\n";   // no factor of 2
        else if (c == 1) cout << "Same\n";  // exactly one factor of 2
        else            cout << "Even\n";   // two or more factors of 2
    }
    return 0;
}
