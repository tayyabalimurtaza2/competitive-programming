#include <iostream>
#include <string>
using namespace std;

int main() {
    string words[3];
    cin>>words[0] >> words[1] >> words[2];
    string t; cin>>t;
    string ans ;
    for(char c : t ){
        ans += words[c-'1'];
    }
    cout << ans;
}