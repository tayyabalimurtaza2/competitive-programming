#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, C;
    cin >> T >> C;

    while (T--) {
        int N;
        cin >> N;

        string L, R;
        cin >> L >> R;

        // Each cow is a directed edge:
        // L[i] -> R[i]
        //
        // J = 1, N = 0
        vector<int> adj[2];

        for (int i = 0; i < N; i++) {
            int u = (L[i] == 'J');
            int v = (R[i] == 'J');
            adj[u].push_back(i);
        }

        // Euler balance:
        // number of edges leaving each vertex
        // must equal number entering it.
        int cntLJ = count(L.begin(), L.end(), 'J');
        int cntRJ = count(R.begin(), R.end(), 'J');

        bool ok = (cntLJ == cntRJ);

        // Going across cow i changes the farmer assignment by
        // 1 - R[i].
        //
        // Around the whole cycle the total change must be 0 mod 2,
        // so the number of R[i] = N must be even.
        int cntRN = count(R.begin(), R.end(), 'N');

        if (cntRN % 2 != 0)
            ok = false;

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        // If C = 0, we don't need the construction.
        if (C == 0) {
            cout << "YES\n";
            continue;
        }

        /*
         * Hierholzer's algorithm for the Eulerian cycle.
         *
         * There are only two vertices, so this is very simple.
         */
        vector<int> ptr(2, 0);
        vector<int> stV;
        vector<int> stE;
        vector<int> circuit;

        // Find a vertex with an outgoing edge.
        int start = -1;
        for (int v = 0; v < 2; v++) {
            if (!adj[v].empty()) {
                start = v;
                break;
            }
        }

        stV.push_back(start);
        stE.push_back(-1);

        while (!stV.empty()) {
            int v = stV.back();

            if (ptr[v] < (int)adj[v].size()) {
                int e = adj[v][ptr[v]++];
                int to = (R[e] == 'J');

                stV.push_back(to);
                stE.push_back(e);
            } else {
                int e = stE.back();

                stV.pop_back();
                stE.pop_back();

                if (e != -1)
                    circuit.push_back(e);
            }
        }

        reverse(circuit.begin(), circuit.end());

        // Safety check.
        if ((int)circuit.size() != N) {
            cout << "NO\n";
            continue;
        }

        /*
         * circuit[k] is the cow at position k.
         *
         * Determine farmer assignments.
         *
         * Let x_i = 1 if cow i is John, 0 otherwise.
         *
         * For an edge i -> next:
         *
         *     x_i XOR x_next = 1 - R[i]
         *
         * Start arbitrarily with John.
         */
        string ans(N, 'N');

        int x = 1; // first cow is John

        for (int k = 0; k < N; k++) {
            int cow = circuit[k];
            ans[cow] = (x ? 'J' : 'N');

            // Move to the next cow.
            int change = (R[cow] == 'N');
            x ^= change;
        }

        // Because cntRN is even, we return to the initial assignment.
        cout << "YES\n";

        for (int i = 0; i < N; i++) {
            if (i) cout << ' ';
            cout << circuit[i] + 1;
        }
        cout << '\n';

        for (int i = 0; i < N; i++)
            cout << ans[circuit[i]];
        cout << '\n';
    }

    return 0;
}
