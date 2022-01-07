#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n,m0,r,pos,r0;
    while (cin>>m>>n){
        m0=m;
        vector <vector<int>> mat;
        for (int er=0; er<m0; ++er){
            vector <int> v(n,0);
            vector <int> w;
            cin>>r;
            r0=r;
            if(r!=0){
                while (r--){cin>>pos; w.push_back(pos-1);}
                for(int i=0; i<r0; ++i){
                    cin>>pos; 
                    v[w[i]] = pos;
                }
            }
            mat.push_back(v); 
        }
        cout << n <<  " " << m << "\n"; 
        for(int i=0; i<n; ++i){
            vector<int> u; vector<int> p;
            for(int k=0; k<m; ++k){
                if(mat[k][i]!=0) {p.push_back(k); u.push_back(mat[k][i]);}
            }
            cout << u.size();
            for(int q:p){cout<< " " << q+1;}
            cout << "\n";
            for(int q=0; q<u.size();++q){
                if(q==u.size()-1){cout << u[q];}
                else cout << u[q] << " ";
            }
            cout << "\n";
        }
    }
}