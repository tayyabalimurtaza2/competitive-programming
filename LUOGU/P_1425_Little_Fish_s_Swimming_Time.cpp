#include <iostream>
using namespace std;
int main(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    int t = (c*60+d) - (a*60+b);
    cout << t/60 << " " << t%60;
}