#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;                       // 64-bit: a+b reaches 2e9, only ~7% under INT_MAX
    cin >> a >> b;
    if ((a + b) % 2) cout << "IMPOSSIBLE\n";   // odd sum -> midpoint not an integer
    else cout << (a + b) / 2 << '\n';
    return 0;
}