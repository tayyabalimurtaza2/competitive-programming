#include <iostream>
using namespace std;
int main(){
    int t; cin>>t;

    while(t--){
        int b,p,f; cin>>b>>p>>f;
        int h,c; cin>>h>>c;
        int ht = 0 ; 
        int ct = 0 ;

        if(h>c){
            
        while (b>=2 && p > 0){
            b-=2 ; p--;
            ht++;
        }
        while(b>=2 && f>0){
            b-=2; f--;
            ct ++;
        }
        }
        else {
        while(b>=2 && f>0){
            b-=2; f--;
            ct ++;
        }
        while (b>=2 && p > 0){
            b-=2 ; p--;
            ht++;
        }
        }
        cout << ht * h + ct * c << endl;  
    }



}