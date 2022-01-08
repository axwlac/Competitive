#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n, n){
        vector <int> v(n);
        vector <int> kad(n);
        for(int i=0; i < n; ++i) cin >> v[i];
        kad[0]=v[0];
        int maxi = v[0];
        for(int i=1; i < n; ++i){
            kad[i]  = max(v[i], v[i] + kad[i-1]);
            if(kad[i]>maxi) maxi = kad[i];
        }
        if(maxi <= 0) cout << "Losing streak.\n";
        else cout << "The maximum winning streak is " << maxi << ".\n";
    }
    
}