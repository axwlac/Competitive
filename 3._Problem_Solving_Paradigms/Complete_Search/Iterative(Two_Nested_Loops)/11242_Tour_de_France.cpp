#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
const int INF = 1e9;


int main(){
    int r, f;
    while(cin >> r, r){
        cin >> f;
        vector <double> R(r), F(f), s(r*f);
        int x=0;
        for(int i=0; i<r; i++) cin >> R[i];
        for(int i=0; i<f; i++) {
            cin >> F[i];
            for(int j=0; j<r; j++){
                s[x] = F[i]/R[j];
                x++;
            }
        }
        sort(s.begin(), s.end());
        double m=-1e9;
        // for(auto d : s) cout << d << " ";
        // cout << "\n";
        for(int i=1; i<r*f; i++){
            m = max(m, s[i]/s[i-1]);
        }
        cout<< fixed << setprecision(2) <<m << "\n";
    }
}