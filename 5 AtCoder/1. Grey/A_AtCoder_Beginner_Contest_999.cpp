#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int ans = 0;
    int place = 1;
    while (a > 0)
    {
        int d = a % 10;
        ans += (10 - d) * place;
        place *= 10;
        a /= 10;
    }
    cout << ans;
}