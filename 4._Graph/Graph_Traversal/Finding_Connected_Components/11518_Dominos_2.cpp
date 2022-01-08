#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m,l,x,y,z; cin >> n >> m >> l;
        vector<vector<int>> AL(n, vector<int>());
        vector <bool> fall (n, false);
        while(m--){
            cin >> x >> y;
            x--; y--;
            AL[x].push_back(y);
        }
        while(l--){
            cin >> z;
            z--;
            vector <int> dist(n, INF); dist[z] = 0;
            queue <int> q; q.push(z);
            fall[z] = true;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(auto &v: AL[u]){
                    if(dist[v] !=  INF) continue;
                    dist[v] = dist[u] + 1;
                    fall[v] = true;
                    q.push(v);
                }
            }
        }

        int f=0; 
        for(auto k: fall) if(k) f++;
        cout << f << "\n";
    }
}