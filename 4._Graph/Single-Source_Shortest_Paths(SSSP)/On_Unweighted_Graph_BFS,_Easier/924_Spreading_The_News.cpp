#include <bits/stdc++.h> 
using namespace std;
typedef vector <int> vi;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int E,t,s;
    cin >> E;
    vector<vi> AL(E, vi());
    for(int i =0 ; i < E; ++i){
        int n, f; cin >> n;
        while (n--){
            cin >> f;
            AL[i].push_back(f);
        }
    }
    cin >> t;
    while (t--){
        cin >> s;
        map <int, int> M;
        vi dist(E, INF); dist[s] = 0;
        queue <int> q; q.push(s);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for(auto v: AL[u]){
                if(dist[v] != INF) continue;
                dist[v] = dist[u] + 1;
                M[dist[v]] ++;
                q.push(v);
            }
        }
        int maxi = 0, first;
        for(auto x: M){
            if(x.second > maxi) {
                maxi = x.second;
                first = x.first;
            }
        }
        if(maxi==0){
            cout << "0\n";
            continue;
        }
        cout << maxi << " " << first << "\n";
    }
    
}