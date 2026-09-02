#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#ifdef __SIZEOF_INT128__ // __int128 only exists on 64-bit compilers
using i128 = __int128;
using u128 = unsigned __int128;
#endif
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vvi = vector<vi>;
using vvll = vector<vll>;
using vvc = vector<vc>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

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

ll floor_div(ll a, ll b) {
    if (b < 0) { a = -a; b = -b; }
    if (a >= 0) return a / b;
    return (a + 1) / b - 1;
}

ll ceil_div(ll a, ll b) {
    if (b < 0) { a = -a; b = -b; }
    if (a <= 0) return a / b;
    return (a - 1) / b + 1;
}

ll power(ll a, ll b, ll mod_val = MOD) {
    ll res = 1;
    a %= mod_val;
    for (; b; b >>= 1, a = a * a % mod_val)
        if (b & 1) res = res * a % mod_val;
    return res;
}

int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int popcount(ll x) { return __builtin_popcountll(x); }

void start() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin>>n;
     int ans = 0 ; 
    while(n--){
       
        int a,b,c; cin>>a>>b>>c;
        if(a+b+c>=2) ans ++;
    }
    cout << ans ;
}

int main() {
    start();
    solve();
    return 0;
}