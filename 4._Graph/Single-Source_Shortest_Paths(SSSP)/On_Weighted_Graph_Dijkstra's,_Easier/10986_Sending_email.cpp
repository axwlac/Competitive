#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,n,m,s,t;
    cin >> N;
    for (int i=0; i < N; ++i){
        cout << "Case #" << i+1 << ": ";
        cin >> n >> m >> s >> t;
        vector<vii> Al(n, vii ());
        while (m--){
            int n1, n2, w;
            cin >> n1 >> n2 >> w;
            Al[n1].push_back({n2,w});
            Al[n2].push_back({n1,w});
        }
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
        if(dist[t]!=INF)cout << dist[t] << "\n";
        else cout << "unreachable\n";
    }
    return 0;
}