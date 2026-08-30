#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> ans(3), guess(3);

    for (auto &s : ans) cin >> s;
    for (auto &s : guess) cin >> s;

    int green = 0;

    // Remaining frequencies after removing green matches
    int cntAns[26] = {};
    int cntGuess[26] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ans[i][j] == guess[i][j]) {
                green++;
            } else {
                cntAns[ans[i][j] - 'A']++;
                cntGuess[guess[i][j] - 'A']++;
            }
        }
    }

    int yellow = 0;

    for (int c = 0; c < 26; c++) {
        yellow += min(cntAns[c], cntGuess[c]);
    }

    cout << green << '\n';
    cout << yellow << '\n';

    return 0;
}