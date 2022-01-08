#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,e,t,m;
    cin >> c;
    while (c--){
        cin >> n >> e >> t >> m;
        e--;
        vector<vii> Al(n, vii ());
        while (m--){
            int a,b,u;
            cin >> a >> b >> u;
            a--; b--;
            Al[a].push_back({b,u});
        }
        int conta =0;
        for(int s=0; s < n; ++s){
            vi dist(n, INF); dist[s]=0;
            priority_queue<ii, vector<ii>, greater<ii>> pq;
            for(int u=0; u < n ; ++u){pq.emplace(0, s);}
            while(!pq.empty()){
                auto p = pq.top(); pq.pop();
                int d = p.first, u = p.second;
                if(d > dist[u]) continue;
                for(auto x: Al[u]){
                    int v = x.first, w = x.second;
                    if(dist[u] + w >= dist[v]) continue;
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
            if(dist[e]<= t) conta++;
        }
        cout << conta << "\n";
        if(c) cout << "\n";
    }
    
}