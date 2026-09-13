#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int bef[4], aft[4];
    int newp = 0;                          // new registrants (all enter at bronze)
    for (int i = 0; i < 4; i++) {
        cin >> bef[i] >> aft[i];
        newp += aft[i] - bef[i];           // total change = entrants (no one leaves)
    }

    // Balance at division i:  bef[i] + inflow - outflow = aft[i]
    //   => outflow = bef[i] + inflow - aft[i]  = promotions i -> i+1,
    // and that outflow becomes the inflow of division i+1.
    int inflow = newp, ans[3];             // ans[0]=bronze->silver, ..., ans[2]=gold->plat
    for (int i = 0; i < 3; i++) {
        ans[i] = bef[i] + inflow - aft[i];
        inflow = ans[i];                   // promoted people flow one level up
    }
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << "\n";
    return 0;
}