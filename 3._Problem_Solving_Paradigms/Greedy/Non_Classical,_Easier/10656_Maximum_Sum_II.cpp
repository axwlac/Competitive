#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a=0; 
    while(cin >> n, n){
        bool oc = false;
        for(int i=0; i<n; i++){
            cin >> a;
            if(a>0 && oc) cout << " " << a;
            if(a>0 && !oc){
                cout << a ;
                oc=true;
            }
        }
        if(oc==false) cout << "0";
        cout << "\n";
    }
}