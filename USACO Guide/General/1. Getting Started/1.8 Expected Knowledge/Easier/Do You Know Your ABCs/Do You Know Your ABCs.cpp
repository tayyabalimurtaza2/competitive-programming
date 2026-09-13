#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#ifdef __SIZEOF_INT128__ // __int128 only exists on 64-bit compilers
using i128 = __int128;
#endif
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
    vector<int> v(7);
    for(int i=0;i<7;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int a = v[0];
    int b = v[1];
    int c = v[6] - a - b ;
    cout << a  << " " << b  << " " << c  << " ";
}

int main() {
    start();
    solve();
    return 0;
}