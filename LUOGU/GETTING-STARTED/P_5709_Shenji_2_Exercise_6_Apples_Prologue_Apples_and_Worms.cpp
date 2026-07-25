#include <iostream>
using namespace std;

int main() {
    int m, t, s;
    cin >> m >> t >> s;

    if (t == 0) {
        cout << 0;
        return 0;
    }

    int eaten = (s + t - 1) / t;
    cout << max(0, m - eaten);

    return 0;
}