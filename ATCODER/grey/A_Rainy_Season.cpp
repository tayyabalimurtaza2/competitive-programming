#include <iostream>
using namespace std; 
int main(){
    string s; cin>>s;
    int t = 0 ;
    int temp = 0 ; 
    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            temp ++;
        }
        else temp = 0;
        t = max(t,temp);
    }
    cout << t ;
}