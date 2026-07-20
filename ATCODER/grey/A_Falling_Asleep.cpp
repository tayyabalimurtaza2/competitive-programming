#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int total =0 ; 
    vector<pair<string , int>> v;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int t; cin>>t;
        total +=t;
        v.push_back({s,t});
    }
    string j; cin>>j;
    for(int i=0;i<n;i++){
        total -= v[i].second;
        if(v[i].first == j) break;
    }
    cout << x ;
    

    

    
}
