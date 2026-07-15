#include <iostream>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    s[k-1] = tolower(s[k-1]);
    // or 
     //s[k-1] = s[k-1] + 32;
    cout << s ;
}