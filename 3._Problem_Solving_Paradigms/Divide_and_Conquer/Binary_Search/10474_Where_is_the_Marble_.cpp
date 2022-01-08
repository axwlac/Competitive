#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q,i=1;
    while (cin>>n>>q,(n||q)){
        cout << "CASE# " << i++ << ":\n";
        vector <int> marbles(n);
        for(int i=0; i < n ; ++i) cin >> marbles[i];
        sort(marbles.begin(), marbles.end());
        while (q--){
            int c ; cin >> c;
            int l=-1, r=n;
            while (r > l + 1){
                int m = ( l + r) / 2;
                if(marbles[m] < c) l = m;
                else r = m;
            }
            if(marbles[r]==c) cout << c << " found at " << r+1 << "\n";
            else cout << c << " not found\n";
        }
    }
    
}