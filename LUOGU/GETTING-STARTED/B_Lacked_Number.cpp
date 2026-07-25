#include <iostream>
using namespace std;
int main(){
    string s; cin>>s;
    bool seen[10] = {}; // nothing means all false
    for(char c : s){
        seen[c-'0'] = true;
    }
    for(int i=0;i<=s.size();i++){
        if(!seen[i]){
            cout << i << '\n';
            break;
        }
    }
}