#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    int t; cin >> t;
    for(int k=1; k<=t; k++){
        int n, p, q;
        cin >> n >> p >> q;
        vi eggs(n);
        for(int i=0; i<n; i++) cin >> eggs[i];
        sort(eggs.begin(), eggs.end());
        int sum=0, ind=INF;
        bool fin = true;
        for(int i=0; i<p; i++){
            if(sum+eggs[i]<=q) sum += eggs[i];
            else{ind = i; fin =false;break;}
        }
        if(fin) ind = p;
        if(ind>p) ind = p;
        if(ind>n) ind = n;
        cout << "Case " << k << ": " << ind << endl;
    }
}