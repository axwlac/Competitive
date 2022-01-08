#include <bits/stdc++.h>
using namespace std;
double p,q,r,s,t,u;

bool good(double x){
    return (p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*x*x)+u>=0;
}


int main(){
    ios::sync_with_stdio(false);
    while (cin>>p>>q>>r>>s>>t>>u){
        if(good(0) && (p*exp(-1))+(q*sin(1))+(r*cos(1))+(s*tan(1))+(t*1)+u<=0){
            double l=0, r=1;
            for(int i=0; i < 100; ++i){
                double m = (r + l) / 2.0;
                if(good(m)) l = m;
                else r = m;
            }
            cout << fixed << setprecision(4) << l << "\n";
        }
        else cout << "No solution\n";
    }
    
}