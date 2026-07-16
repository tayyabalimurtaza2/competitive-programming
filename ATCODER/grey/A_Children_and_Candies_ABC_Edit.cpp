https://atcoder.jp/contests/abc043/tasks/abc043_a
#include <iostream>
using namespace std;
int main(){
    int a; cin>>a;
    int t = 0 ; 
    for(int i=1;i<=a;i++){
        t += i;
    }
    cout << t;
}