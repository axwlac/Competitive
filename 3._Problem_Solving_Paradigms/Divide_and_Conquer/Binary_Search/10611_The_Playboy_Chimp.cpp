#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,q,x;
    cin >> n;
    vector <int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    cin >> q;
    while (q--){
        cin >> x;
        int l=-1, r=n;
        while (r > l + 1){
            int m = ( l + r) / 2;
            if(v[m] > x) r = m;
            else l = m;
        }
        int u=-1, h=n;
        while (h > u + 1){
            int m = ( h + u) / 2;
            if(v[m] < x) u = m;
            else h = m;
        }

        if(r==n) cout << v[u] <<  " X\n";
        else if(u==-1) cout << "X " << v[r] << "\n";
        else cout << v[u] << " " << v[r] << "\n";
    }  
}    