// Statistics
#include <iostream>
using namespace std;
int main(){
    int a,b; cin>>a>>b;
    int ans = 0 ; 
    for(int i=a;i<=b;i++){
        string s = to_string(i);
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'== 2) ans ++;
        }
    }
    cout << ans ;
}