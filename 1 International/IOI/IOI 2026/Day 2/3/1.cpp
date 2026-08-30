#include <bits/stdc++.h>
using namespace std;

static int nRows, nCols;
static vector<vector<char>> occ;

// Safe-corner type:
// C_TL = top-left tile
// C_TR = top-right tile
// C_BL = bottom-left tile
// C_BR = bottom-right tile
enum { C_TL = 0, C_TR = 1, C_BL = 2, C_BR = 3 };

static int ptrR[4], ptrC[4];

static bool inside(int r, int c) {
    return 0 <= r && r < nRows && 0 <= c && c < nCols;
}

static void advancePtr(int t) {
    if (t == C_TL) {
        ptrC[t]--;
        if (ptrC[t] < 0) {
            ptrC[t] = nCols - 1;
            ptrR[t]--;
        }
    } else if (t == C_TR) {
        ptrC[t]++;
        if (ptrC[t] >= nCols) {
            ptrC[t] = 0;
            ptrR[t]--;
        }
    } else if (t == C_BL) {
        ptrC[t]--;
        if (ptrC[t] < 0) {
            ptrC[t] = nCols - 1;
            ptrR[t]++;
        }
    } else { // C_BR
        ptrC[t]++;
        if (ptrC[t] >= nCols) {
            ptrC[t] = 0;
            ptrR[t]++;
        }
    }
}

static pair<int, int> takeCell(int t) {
    while (inside(ptrR[t], ptrC[t]) && occ[ptrR[t]][ptrC[t]]) {
        advancePtr(t);
    }

    int r = ptrR[t], c = ptrC[t];
    occ[r][c] = 1;
    advancePtr(t);
    return {2 * r, 2 * c};
}

void init(int N, int M) {
    nRows = N;
    nCols = M;
    occ.assign(N, vector<char>(M, 0));

    // Cursors fill each corner type from its own corner.
    ptrR[C_TL] = N - 1; ptrC[C_TL] = M - 1; // bottom-right
    ptrR[C_TR] = N - 1; ptrC[C_TR] = 0;      // bottom-left
    ptrR[C_BL] = 0;     ptrC[C_BL] = M - 1;  // top-right
    ptrR[C_BR] = 0;     ptrC[C_BR] = 0;      // top-left
}

pair<int, int> receive_block(int TL, int TR, int BL, int BR) {
    // Use any white tile as the "safe tile".
    if (TL == 0) return takeCell(C_TL);
    if (TR == 0) return takeCell(C_TR);
    if (BL == 0) return takeCell(C_BL);
    if (BR == 0) return takeCell(C_BR);

    // Never reached because every block has at least one white tile.
    return {-1, -1};
}