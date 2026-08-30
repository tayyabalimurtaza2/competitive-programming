#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    vector<int> thresholds = {40, 70, 90};
    for (int t : thresholds) {
        if (x < t) {
            cout << t - x << "\n";
            return 0;
        }
    }
    cout << "expert\n";

    return 0;
}
