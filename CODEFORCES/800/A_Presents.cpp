#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a; cin>>a;
    vector<int> giver(a+1);
    for(int n=1;n<=a;n++){
        int p; cin>>p;
        giver[p] = n;  
    }

    for(int i=1;i<=a;i++){
        cout << giver[i] << " ";
    }
}