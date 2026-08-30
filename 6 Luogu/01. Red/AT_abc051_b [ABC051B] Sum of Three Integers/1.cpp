#include <bits/stdc++.h>
using namespace std;

const int LOG = 18; // 2^17 > 1e5

int n, m;

vector<int> parent_;
vector<int> parentTime;

vector<vector<int>> up;
vector<vector<int>> mx;

vector<vector<int>> children;
vector<int> tin, tout;
int timer = 0;

void dfs(int u) {
    tin[u] = ++timer;

    for (int v : children[u]) {
        dfs(v);
    }

    tout[u] = timer;
}

bool isAncestor(int u, int v) {
    // Is u an ancestor of v?
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

// Maximum edge creation time on path v -> ancestor u
int maxTimeToAncestor(int v, int u) {
    int ans = 0;

    for (int j = LOG - 1; j >= 0; --j) {
        // We can jump if the resulting node is still
        // at or below u.
        if (up[j][v] != 0 && !isAncestor(up[j][v], u)) {
            ans = max(ans, mx[j][v]);
            v = up[j][v];
        }
    }

    // Now v should be the direct child of u.
    if (v != u) {
        ans = max(ans, mx[0][v]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    parent_.assign(n + 1, 0);
    parentTime.assign(n + 1, 0);
    children.assign(n + 1, {});

    // Store events first.
    // packetSource[i] = employee receiving packet i
    // packetTime[i]   = event number when packet was created
    vector<pair<int, vector<int>>> events;

    vector<int> packetSource(1);
    vector<int> packetTime(1);

    for (int t = 1; t <= m; ++t) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;

            // y becomes boss of x at time t
            parent_[x] = y;
            parentTime[x] = t;

        } else if (type == 2) {
            int x;
            cin >> x;

            packetSource.push_back(x);
            packetTime.push_back(t);

        } else {
            int x, i;
            cin >> x >> i;

            events.push_back({x, {i}});
        }
    }

    // Build final forest.
    for (int v = 1; v <= n; ++v) {
        if (parent_[v] != 0) {
            children[parent_[v]].push_back(v);
        }
    }

    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);

    // DFS every root.
    for (int v = 1; v <= n; ++v) {
        if (parent_[v] == 0) {
            dfs(v);
        }
    }

    // Binary lifting.
    up.assign(LOG, vector<int>(n + 1, 0));
    mx.assign(LOG, vector<int>(n + 1, 0));

    for (int v = 1; v <= n; ++v) {
        up[0][v] = parent_[v];
        mx[0][v] = parentTime[v];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int v = 1; v <= n; ++v) {
            int mid = up[j - 1][v];

            if (mid != 0) {
                up[j][v] = up[j - 1][mid];
                mx[j][v] = max(mx[j - 1][v], mx[j - 1][mid]);
            }
        }
    }

    for (auto &[x, data] : events) {
        int i = data[0];

        int source = packetSource[i];
        int time = packetTime[i];

        // x must be an ancestor of the packet source.
        if (!isAncestor(x, source)) {
            cout << "NO\n";
            continue;
        }

        // All boss relationships on source -> x
        // must already exist when packet was created.
        int latest = maxTimeToAncestor(source, x);

        if (latest <= time)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}