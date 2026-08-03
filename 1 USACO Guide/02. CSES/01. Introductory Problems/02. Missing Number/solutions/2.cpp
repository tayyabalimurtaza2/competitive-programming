#include <iostream>
using namespace std;
int main(){
    long long  x; cin>>x;
    long long  t = x*(x+1)/2;
    for(int i=1;i<x;i++){
        int  a; cin>>a; 
        t -= a;
    }
    cout <<t ;
}