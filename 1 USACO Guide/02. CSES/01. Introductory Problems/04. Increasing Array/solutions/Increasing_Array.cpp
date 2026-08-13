// Increasing Array
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int x; cin>>x;
    vector<int> v(x);
    for(int i=0;i<x;i++){
        cin>>v[i];
    }
    long long  ans = 0 ; 
    for(int i=1;i<x;i++){
        while(v[i] < v[i-1]){
            v[i] ++;
            ans ++ ; 
        }
    }
    cout << ans ;
    
}