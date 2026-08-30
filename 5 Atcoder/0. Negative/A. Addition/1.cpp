#include <bits/stdc++.h>
using namespace std;
int main(){
    int x; cin>>x;
    long long sum = 0 ;
    while(x--){
        long long l; cin>>l;
        sum+=l;
    }
    cout << ((sum&2) ? "NO" : "YES");
}
