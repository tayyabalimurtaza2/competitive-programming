#include <bits/stdc++.h>
using namespace std;

// Recurse first, print after returning => reverse order via call stack.
void solve(int n) {
    if (n == 1) { cout << 1; return; }   // terminal: prints the final 1
    int next = (n & 1) ? n * 3 + 1 : n / 2;
    solve(next);                         // prints 1 ... next
    cout << ' ' << n;                     // then append current
}

int main() {
    int n;
    cin >> n;
    solve(n);
    cout << '\n';
    return 0;
}
