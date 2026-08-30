#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, N;
    cin >> X >> N;

    // We will mark forbidden numbers in a boolean array.
    // Allowed indices: we use offset 200 so that index 200 corresponds to value 0.
    // Index = value + 200  ->  value = index - 200
    // The possible values we check are from -200 to 200, so index 0..400.
    bool forbidden[401] = {false};  // initialize all to false

    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        forbidden[p + 200] = true;  // mark p as forbidden
    }

    // Start checking from distance 0 outward
    for (int d = 0; ; ++d) {
        // Check X - d (smaller first)
        int left = X - d;
        if (left >= -200 && left <= 200 && !forbidden[left + 200]) {
            cout << left << '\n';
            break;
        }
        // Check X + d
        int right = X + d;
        if (right >= -200 && right <= 200 && !forbidden[right + 200]) {
            cout << right << '\n';
            break;
        }
        // If both are forbidden, continue to next distance
    }

    return 0;
}
