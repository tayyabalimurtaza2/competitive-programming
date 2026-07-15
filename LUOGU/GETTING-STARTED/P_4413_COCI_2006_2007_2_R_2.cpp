#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

#define PB push_back
#define F first
#define S second

void start(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MOD = 1e9 + 7;

int main(){
    start();

    int r1,s; cin>>r1>>s;
    int r2 = 2*s - r1;
    cout << r2;

    return 0;
}