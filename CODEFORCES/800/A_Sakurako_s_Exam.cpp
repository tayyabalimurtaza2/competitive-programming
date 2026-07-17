#include <iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        bool yes;
        if(a%2!=0){
            yes = false;
        }
        else if(a==0){
            yes = (b%2==0);
        }
        else yes = true;
        cout << (yes ? "YES" : "NO") << endl;
    }
    
}