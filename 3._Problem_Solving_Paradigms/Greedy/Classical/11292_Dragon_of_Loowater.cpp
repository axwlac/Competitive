#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n,m;
    while (cin>>n>>m, (n||m)){
         vector <int> D(n),H(m);
        for(int i=0; i < n; ++i) cin >> D[i];
        for(int i=0; i < m; ++i) cin >> H[i];
        sort(D.begin(), D.end());
        sort(H.begin(), H.end());
        int gold =0, d=0, k=0;
        while((d < n) && (k < m)){
            while ((k < m) && (D[d] > H[k])) ++k;
            if(k==m)break;
            gold += H[k];
            ++d; ++k;
        }
        if(d == n) cout << gold << "\n";
        else cout << "Loowater is doomed!\n";
    }
    
}