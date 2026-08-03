#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    cin >> x;

    vector<string> v(x);

    for (int i = 0; i < x; i++) {
        cin >> v[i];
    }

    int ans = 1;

    for (int i = 0; i < x - 1; i++){
        if (v[i] != v[i + 1]) {
            ans++;
        }
    }

    cout << ans << endl;
}