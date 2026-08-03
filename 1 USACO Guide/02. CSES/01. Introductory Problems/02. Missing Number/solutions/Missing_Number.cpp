    #include <iostream>
    #include <vector>
    #include <algorithm>        
    using namespace std;
    int main(){
        long long x; cin>>x;
        vector<long long > v(x);
        for(int i=0;i<x-1;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<=x;i++){
            if(v[i]!=i) {
                cout << i ;
                break;
            }
        }
    }