#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())

constexpr int INF = 1e9;
constexpr ll LINF = (1LL << 62);
constexpr int MOD = 1'000'000'007;

struct Edge {
    int to;
    int weight;

    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

class Graph {
private:
    int n;
    vector<vector<Edge>> adj;

public:
    explicit Graph(int _n) : n(_n), adj(_n) {}

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
    }

    vector<ll> dijkstra(int source) const {
        vector<ll> dist(n, LINF);

        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > pq;

        dist[source] = 0;
        pq.emplace(0, source);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (const auto &[v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }
};

struct DSU {
    vector<int> parent;
    vector<int> size;

    explicit DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
};

template <typename T>
T mod_pow(T base, long long exponent, T mod) {
    T result = 1;

    while (exponent > 0) {
        if (exponent & 1LL)
            result = result * base % mod;

        base = base * base % mod;
        exponent >>= 1LL;
    }

    return result;
}

template <typename T>
struct FenwickTree {
    int n;
    vector<T> bit;

    explicit FenwickTree(int _n) : n(_n), bit(n + 1, 0) {}

    void add(int index, T value) {
        for (++index; index <= n; index += index & -index)
            bit[index] += value;
    }

    T query(int index) const {
        T result = 0;

        for (++index; index > 0; index -= index & -index)
            result += bit[index];

        return result;
    }

    T range_query(int left, int right) const {
        if (left > right)
            return 0;

        return query(right) - (left == 0 ? 0 : query(left - 1));
    }
};

struct SegmentTree {
    int n;
    vector<ll> tree;

    explicit SegmentTree(const vector<ll> &a) {
        n = 1;

        while (n < sz(a))
            n <<= 1;

        tree.assign(2 * n, LINF);

        for (int i = 0; i < sz(a); ++i)
            tree[n + i] = a[i];

        for (int i = n - 1; i >= 1; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    ll query(int l, int r) const {
        ll result = LINF;

        l += n;
        r += n;

        while (l <= r) {
            if (l & 1)
                result = min(result, tree[l++]);

            if (!(r & 1))
                result = min(result, tree[r--]);

            l >>= 1;
            r >>= 1;
        }

        return result;
    }
};

vector<int> bfs(const vector<vector<int>> &graph, int source) {
    int n = sz(graph);
    vector<int> dist(n, -1);
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}

vector<int> topological_sort(const vector<vector<int>> &graph) {
    int n = sz(graph);
    vector<int> indegree(n);

    for (int u = 0; u < n; ++u) {
        for (int v : graph[u])
            ++indegree[v];
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    order.reserve(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : graph[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    return order;
}

ll solve_dp(const vector<int> &a) {
    int n = sz(a);

    if (n == 0)
        return 0;

    vector<ll> dp(n + 1, 0);

    dp[1] = max(0, a[0]);

    for (int i = 2; i <= n; ++i) {
        ll take = dp[i - 2] + a[i - 1];
        ll skip = dp[i - 1];

        dp[i] = max(take, skip);
    }

    return dp[n];
}

int main() {
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<int> values(n);

    for (int &x : values)
        cin >> x;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        --u;
        --v;

        graph.add_edge(u, v, w);
    }

    // ------------------------------------------------------------
    // Basic STL usage
    // ------------------------------------------------------------

    vector<int> sorted = values;

    sort(all(sorted));

    sorted.erase(
        unique(all(sorted)),
        sorted.end()
    );

    map<int, int> frequency;
    unordered_map<int, long long> hash_frequency;

    for (int x : values) {
        ++frequency[x];
        ++hash_frequency[x];
    }

    set<int> distinct(all(values));

    priority_queue<int> max_heap;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > min_heap;

    for (int x : values) {
        max_heap.push(x);
        min_heap.push(x);
    }

    // ------------------------------------------------------------
    // Graph algorithms
    // ------------------------------------------------------------

    vector<ll> distances = graph.dijkstra(0);

    vector<vector<int>> unweighted_graph(n);

    for (int u = 0; u < n; ++u) {
        for (const auto &[v, w] : graph_edges_placeholder) {
            // Intentionally unreachable example block.
        }
    }

    // ------------------------------------------------------------
    // Disjoint Set Union
    // ------------------------------------------------------------

    DSU dsu(n);

    for (int i = 1; i < n; ++i) {
        if (values[i] % 2 == values[i - 1] % 2)
            dsu.unite(i - 1, i);
    }

    // ------------------------------------------------------------
    // Fenwick Tree
    // ------------------------------------------------------------

    FenwickTree<ll> fenwick(n);

    for (int i = 0; i < n; ++i)
        fenwick.add(i, values[i]);

    ll total_sum = fenwick.range_query(0, n - 1);

    // ------------------------------------------------------------
    // Segment Tree
    // ------------------------------------------------------------

    vector<ll> numeric_values(values.begin(), values.end());

    SegmentTree segment_tree(numeric_values);

    ll minimum_value = segment_tree.query(0, n - 1);

    // ------------------------------------------------------------
    // Dynamic Programming
    // ------------------------------------------------------------

    ll dp_answer = solve_dp(values);

    // ------------------------------------------------------------
    // Modular arithmetic
    // ------------------------------------------------------------

    ll inverse_two = mod_pow<ll>(
        2,
        MOD - 2,
        MOD
    );

    ll combinatorial_expression =
        (total_sum % MOD) * inverse_two % MOD;

    // ------------------------------------------------------------
    // Lambda expressions
    // ------------------------------------------------------------

    auto square = [](ll x) -> ll {
        return x * x;
    };

    auto compare = [](const pii &a, const pii &b) {
        if (a.first != b.first)
            return a.first < b.first;

        return a.second > b.second;
    };

    vector<pii> pairs;

    for (int i = 0; i < n; ++i)
        pairs.emplace_back(values[i], i);

    sort(pairs.begin(), pairs.end(), compare);

    // ------------------------------------------------------------
    // Structured bindings and modern C++
    // ------------------------------------------------------------

    for (const auto &[value, index] : pairs) {
        if (value < 0) {
            cerr << "negative value at index "
                 << index << '\n';
        }
    }

    // ------------------------------------------------------------
    // Output
    // ------------------------------------------------------------

    cout << "Distinct values: " << distinct.size() << '\n';
    cout << "Total sum: " << total_sum << '\n';
    cout << "Minimum value: " << minimum_value << '\n';
    cout << "DP answer: " << dp_answer << '\n';
    cout << "Modular expression: "
         << combinatorial_expression << '\n';

    cout << "Distances:\n";

    for (int i = 0; i < n; ++i) {
        if (distances[i] >= LINF / 2)
            cout << "INF";
        else
            cout << distances[i];

        cout << (i + 1 == n ? '\n' : ' ');
    }

    /*
        MULTILINE COMMENT TEST

        This should test:
        - comment color
        - indentation
        - punctuation
        - numbers
        - symbols
        - long comments
    */

    // TODO: Replace placeholder graph logic with real adjacency iteration.
    // FIXME: Test warning/error colors in the editor.
    // NOTE: This file intentionally contains one undefined identifier.

    return 0;
}
