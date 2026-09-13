// 1 2 3  = 4 2 = 6 
// 1 1 2 3 = 2 2 3 

// rule  1 = odds must be even 

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int ans = 0 ;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(a%2!=0) ans ++;
    }
    cout << (ans%2==0 ? "YES" : "NO");

}