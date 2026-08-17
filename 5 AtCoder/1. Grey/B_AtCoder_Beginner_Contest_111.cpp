#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int d = x / 100;
    int ans = d * 111;
    if (ans >= x)
        cout << ans;
    else
        cout << (d + 1) * 111;
}