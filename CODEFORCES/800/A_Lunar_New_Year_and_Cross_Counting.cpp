#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    if (n < 3) {
        cout << 0 << '\n';
        return 0;
    }
    
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    int crosses = 0;
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = 1; j <= n - 2; ++j) {
            if (grid[i][j] == 'X' &&
                grid[i-1][j-1] == 'X' &&
                grid[i-1][j+1] == 'X' &&
                grid[i+1][j-1] == 'X' &&
                grid[i+1][j+1] == 'X') {
                ++crosses;
            }
        }
    }
    
    cout << crosses << '\n';
    return 0;
}