#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int n; cin>>n;
    if(n>=90) cout << "expert";
    else if(n>=70) cout << 90-n;
    else if(n>=40) cout << 70-n;
    else  cout <<  40-n;
}