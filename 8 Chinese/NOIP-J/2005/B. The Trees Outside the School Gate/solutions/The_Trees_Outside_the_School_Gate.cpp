#include <iostream>
#include <vector>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;

    // tree[i] = true means there is still a tree at position i
    vector<bool> tree(l + 1, true);

    // Remove trees in each interval
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        for (int j = u; j <= v; j++) {
            tree[j] = false;
        }
    }

    // Count remaining trees
    int ans = 0;
    for (int i = 0; i <= l; i++) {
        if (tree[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}