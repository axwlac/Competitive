#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nc, caso=1;
    while (cin >> nc , nc){
        vector <vector <int>> Al;
        unordered_map <int,int> mapa;
        set <int> S;
        vector <pair<int,int>> v;
        int index=0;
        for (int i=0; i < nc; ++i){
            pair <int,int> x;
            cin >> x.first  >> x.second;
            v.push_back(x);
            S.insert(x.first);
            S.insert(x.second);
        }
        int V = S.size();
        for(auto s: S){mapa[s] = index++;}
        Al.assign(V, vector<int> ());
        for (auto s: v){
            int x,y;
            x = mapa[s.first];
            y = mapa[s.second];
            Al[x].push_back(y);
            Al[y].push_back(x);
        }
        int s, l;
        while (cin >> s >> l, (s||l)){
            if(mapa.find(s) == mapa.end()) cout << "Case " << caso++ << ": " << V << " nodes not reachable from node " << s << " with TTL = " << l  << ".\n";
            else{ 
                int sp = mapa[s];
                vector <int> dist (V,INF); dist[sp]=0;
                queue <int> q; q.push(sp);
                while (!q.empty()){
                    int u = q.front(); q.pop();
                    for(auto &vi : Al[u]){
                        if(dist[vi] != INF) continue;
                        else{
                            dist[vi]= dist[u]+1;
                            q.push(vi);
                        }
                    }
                }
                int c=0;
                for(auto j: dist){
                    if(j <= l) c++;
                }
                cout << "Case " << caso++ << ": " << V-c << " nodes not reachable from node " << s << " with TTL = " << l  << ".\n";
            }
        }
        
        
    }
    
}