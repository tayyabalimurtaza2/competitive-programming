#include <bits/stdc++.h>
using namespace std;
int main(){
    bool seen[26]={};
    string s; cin>>s;
    for(char c:s) {
        seen[c-'a']=1;
    }
    int t=0;
    for(int i=0;i<26;i++) if(seen[i]==1) t++;
    cout << ((t&1)?"IGNORE HIM!" :"CHAT WITH HER!");
}
