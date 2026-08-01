// Tao Tao Picking Apples
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v(10);
    for(int i=0;i<10;i++){
        cin>>v[i];
    }
    int h; cin>>h;
    int n = 0 ;
    for(int i=0;i<10;i++){
        if(h+30>=v[i]) n++;
    }
    cout << n; 

} 