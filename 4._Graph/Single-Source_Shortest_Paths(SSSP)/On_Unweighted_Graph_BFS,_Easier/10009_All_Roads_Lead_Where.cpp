#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
unordered_map <string,int> mapa;
unordered_map <int,string> mapa1;
int s;
vector <int> p;
void printPath(int u){
    if(u == s) {cout << mapa1[s][0]; return;}
    printPath(p[u]);
    cout << mapa1[u][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        mapa.clear();
        mapa1.clear();
        int n,m;
        cin >> m >> n;
        vector <vector <int>> Al;
        set <string> S;
        vector <pair<string,string>> v;
        for(int i=0; i < m ; ++i){
            pair<string,string> p;
            cin >> p.first >> p.second;
            v.push_back(p);
            S.insert(p.first);
            S.insert(p.second);       
        } 
        int V = S.size(), index =0;
        for (auto s: S){
            mapa[s] = index;
            mapa1[index++] = s;
        }
        Al.assign(V, vector<int> ());
        for (auto si: v){
            int x,y;
            x = mapa[si.first];
            y = mapa[si.second];
            Al[x].push_back(y);
            Al[y].push_back(x);
        }
        string l,r;
        while (n--){
            p.clear();
            p.assign(V,-1);
            cin >> l >> r;
            s = mapa[l];
            int j = mapa[r];
            vector <int> dist(V, INF); dist[s]=0;
            queue<int> q; q.push(s);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u == j) break;
                for(auto &vi : Al[u]){
                    if(dist[vi] != INF) continue;
                    dist[vi] = dist[u]+1;
                    p[vi]= u;
                    q.push(vi);
                }
            }
            printPath(j); cout << "\n";
        }
        if(t) cout << "\n";
    }
    
}