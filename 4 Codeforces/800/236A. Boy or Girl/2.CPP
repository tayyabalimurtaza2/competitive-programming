#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int mask = 0;
    for (char c : s) {
        mask |= 1 << (c - 'a');
    }

    if (__builtin_popcount(mask) % 2 == 0) {
        cout << "CHAT WITH HER!\n";
    } else {
        cout << "IGNORE HIM!\n";
    }

    return 0;
}
