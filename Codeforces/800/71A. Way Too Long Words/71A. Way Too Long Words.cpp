#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.size() <= 10) cout << s << '\n';
    else cout << s[0] << s.size() - 2 << s.back() << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}