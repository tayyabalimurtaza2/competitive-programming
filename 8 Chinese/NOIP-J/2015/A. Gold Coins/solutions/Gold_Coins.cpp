// Gold Coins
#include <iostream>
using namespace std;
int main(){
    int n; cin>>n; // 10 
    int ans = 0 ; 
    int c = 1 ; 
    for(int i=1;i<=n;i+=c){
        int a = 0 ;
        for(int j=1;j<=i;j++){
            a ++;
        }
        ans += a * i;
        c += a;
    }
    cout << ans << endl;
    
    
}











