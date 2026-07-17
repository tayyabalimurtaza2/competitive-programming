// https://codeforces.com/contest/2010/problem/A
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

    int t; cin>>t;
    
    while(t--){
        int ans = 0 ; 

        int a; cin>>a;
        
        for(int i=1;i<=a;i++){
            int z; cin>>z;
            if(i%2==0){
                ans -= z;
            }
            else ans += z;
        }
        cout << ans  << endl;
    }

    return 0;
}