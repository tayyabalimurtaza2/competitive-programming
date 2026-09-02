#include <iostream>
using namespace std;
int main(){
    string a,b; cin>>a>>b;
     cout << (b.substr(0,a.size())==a ? "Yes" : "No");

}