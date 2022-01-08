#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld expbase(ld base, ld exponent){
    return exp(exponent*log(base));
}


bool good(ld x, vector<ld> v){
    ld r =0 ;
    for(int i=0; i<v.size(); ++i){
        if(i==0) r += v[i];
        else{
            r += v[i]/(expbase(1+x, (ld)i));
        }
    }
    return r >=0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    while(cin >> t, t){
        vector <ld> v(t+1);
        for(int i=0; i<=t; ++i) cin >> v[i];
        ld l=-1,r=1e9;
        for(int k=0; k<sqrt(1e9); ++k){
            ld m = (l+r)/2;
            if(good(m, v)) l = m;
            else r=m;
        }
        if(l <= -1) cout << "No\n";
        else cout << fixed << setprecision(2) << l << "\n";
    }
}