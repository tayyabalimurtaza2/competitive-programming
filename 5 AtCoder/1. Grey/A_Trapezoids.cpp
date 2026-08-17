#include <iostream>
using namespace std;
int main()
{
    int a, b, h;
    cin >> a >> b >> h;
    long long ans = 1.0 / 2 * (a + b) * h * 1LL;
    cout << ans;
}