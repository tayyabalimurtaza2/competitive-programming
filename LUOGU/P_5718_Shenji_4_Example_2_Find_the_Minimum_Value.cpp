#include <iostream>
#include <climits>
using namespace std;
int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n ; cin>>n;
    int ans = INT_MAX; 
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(a<ans) ans = a;
    }
    cout << ans;
}