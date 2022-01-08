#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m,caso=1;
    while (cin >> n, n){
        cout << "Case " << caso++ << ":\n";
        vector <int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        cin >> m;
        int q;
        while (m--){
            vector <int> res;
            cin >> q;
            for(int i=0; i<n-1; ++i){
                for(int k=i+1; k < n; ++k){
                    res.push_back(v[i]+v[k]);
                }
            }
            sort(res.begin(), res.end());
            int l = -1, r = res.size();
            while (l + 1 < r){
                int m = (l + r) / 2;
                if(res[m] <= q) l = m;
                else r = m;
            }
            //closest right (r0 )
            int l0 = -1, r0 = res.size();
            while (l0 + 1 < r0){
                int m = (l0 + r0) / 2;
                if(res[m] < q) l0 = m;
                else r0 = m;
            }

            if(l!=-1 && r0!=res.size()) {
                int s;
                if(abs(res[l]-q) < abs(res[r0]-q)) s = res[l];
                else s = res[r0];
                cout << "Closest sum to " << q << " is " << s<< ".\n"; continue;}
            if(l==-1) {cout << "Closest sum to " << q << " is " << res[r0] << ".\n"; continue;}
            if(r0==res.size()) cout << "Closest sum to " << q << " is " << res[l] << ".\n";
        }
        
    }
    
}