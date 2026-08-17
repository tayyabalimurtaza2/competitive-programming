#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k, x, y;
    // Guard against EOF (good habit for reusable snippets).
    if (!(cin >> n >> k >> x >> y)) return 0;
    
    long long expensive_nights = min(n, k);          // nights billed at X
    long long cheap_nights     = max(0LL, n - k);    // nights billed at Y
    
    cout << expensive_nights * x + cheap_nights * y << '\n';
    return 0;
}