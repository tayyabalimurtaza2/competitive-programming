// A. Iroha and Haiku (ABC Edition)
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a,b,c; cin>>a>>b>>c;
    vector<int>v = {a,b,c};
    sort(v.begin(),v.end());
    if(v[0]==5 && v[1]==5 && v[2]==7){
        cout << "YES";
    }
    else cout << "NO";
}