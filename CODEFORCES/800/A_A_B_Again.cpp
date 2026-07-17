#include <iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int a; cin>>a;
        int ans = a%10 + a/10%10;
        cout << ans << endl; 
    }
}