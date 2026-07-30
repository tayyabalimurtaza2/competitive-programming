#include <iostream>
using namespace std;
int main(){
    double k; cin >> k;
    double z = 0;
    int c = 0;
    for(int i = 1; ; i++){
        z = z + 1.0 / i;  // Fixed: 1.0 forces floating-point division
        c++;
        if(z > k){
            break;
        }
    }
    cout << c;
} 