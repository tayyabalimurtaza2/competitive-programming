#include <iostream>
using namespace std;
int main(){
    int ans = 0 ; 
    int h = 0 ; 
    for(int i=1;i<=7;i++){
        int a,b; cin>>a>>b;
        int t = a + b ;
        if(a+b>8 && t>ans){
        h = i ;
        ans = t ;
        }
    }
    cout << h ; 
}