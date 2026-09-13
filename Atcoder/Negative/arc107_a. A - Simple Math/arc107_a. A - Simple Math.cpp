#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 998244353;

template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void start() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans =
        (a * a * a) % MOD +
        (a * a * b) % MOD +
        (a * a * c) % MOD +
        (a * b * a) % MOD +
        (a * b * b) % MOD +
        (a * b * c) % MOD;

    ans %= MOD;

    cout << ans << '\n';
}

int main() {
    start();
    solve();
}