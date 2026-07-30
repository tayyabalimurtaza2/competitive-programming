#include <bits/stdc++.h>
using namespace std;

const int MAXA = 500000;
const int MOD = 1000000007;

int min_prime[MAXA + 1];

void sieve() {
    for (int i = 1; i <= MAXA; ++i) min_prime[i] = i;
    for (int i = 2; i * i <= MAXA; ++i) {
        if (min_prime[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (min_prime[j] == j) {
                    min_prime[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    long long ans = 1;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}