#include <iostream>
using namespace std;

int sumofdigits(int n) {
    long long sum = 0;
    while(n>0){
        sum += n%10;
        n /=10;
    }
    return sum;
}

int main(){
    long long x; cin>>x;
    int ans = 0;
    for(int i=1;i<=x;i++){
        int t = sumofdigits(i);
        if(t>ans) ans = t;
    }
    cout << ans << endl;
}