#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,p,u;
    cin >> t;  
    while(t--){
        cin >> n;
        vector<int> par(n);
        cin >> p;
        vector<int>  l(p);
        for(int i = 0; i < p; i++){
            cin >> u;
            l[i] = u; 
        }
        for(int j=0; j < p ;j++){
            int o;
            o = l[j];      
            for(int m = o-1; m < n; m = m + o ){
                if(m%7 == 5 || m%7 == 6) par[m] = 0;
                else par[m] = 1;
            }
        }
        int aux =0;
        for(int y =0; y < n;y++){
            aux = aux + par[y];
        }
        cout << aux << "\n";
    }
}