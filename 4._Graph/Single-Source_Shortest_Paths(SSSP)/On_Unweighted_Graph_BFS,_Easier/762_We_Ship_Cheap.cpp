#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int INF = 1e9;
int s;
vi pa;
map <int, string> node;
vector<string> route;

void printPath(int u){
    if(u == s) {route.push_back(node[s]); return;}
    printPath(pa[u]);
    route.push_back(node[u]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i=0;
    while(cin >> n){
        if(i>0) cout << "\n"; i++;
        route.clear();
        map <string, int> city;
        node.clear();
        string a, b;
        int idx = 0, e;
        vector<pair<int, int>> p;
        while(n--){
            cin >> a >> b;
            if(city.count(a)==0) {city[a] = idx; node[idx++] = a;}
            if(city.count(b)==0) {city[b] = idx; node[idx++] = b;}
            p.push_back({city[a], city[b]});
        }
        cin >> a >> b;

        if(city.count(a)==0) {city[a] = idx; node[idx++] = a;}
        if(city.count(b)==0) {city[b] = idx; node[idx++] = b;}

        e = city[b] ; s = city[a];
        int V = city.size();
        vector <vi> AL(V, vi ());
        pa.assign(V, -1);
        for(auto k: p){
            AL[k.first].push_back(k.second);
            AL[k.second].push_back(k.first);
        }

        vi dist(V, INF); dist[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==e) break;
            for(auto v: AL[u]){
                if(dist[v] != INF) continue;
                dist[v] = dist[u] + 1;
                pa[v] = u;
                q.push(v);
            }
        }

        if(dist[e] == INF){cout << "No route\n"; continue;}

        printPath(e);
        for(int j=0; j < route.size()-1; ++j){
            cout << route[j] << " " << route[j+1] << "\n";
        }
        // cout << "\n";
    }
}