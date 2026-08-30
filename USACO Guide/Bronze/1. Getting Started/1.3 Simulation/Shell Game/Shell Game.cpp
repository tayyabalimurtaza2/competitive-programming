#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 4e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (b > a) { a = b; return true; }
    return false;
}

ll power(ll a, ll b, ll mod_val = MOD) {
    ll res = 1;
    a %= mod_val;
    for (; b; b >>= 1, a = a * a % mod_val)
        if (b & 1) res = res * a % mod_val;
    return res;
}

void start() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin>>n;
    cout << n;
    for(int i=0;i<n;i++){
        int n ;cin>>N;
        cout << x;
    }
}

int main() {
    start();
    solve();
    return 0;
}