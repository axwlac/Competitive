#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> Al;
const int INF = 1e9 ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l;
    while (cin >> n, n){
        cin >> l;
        Al.assign(n, vector <int> ());
        while (l--){
            int x, y;
            cin >> x >> y;
            Al[x].push_back(y);
            Al[y].push_back(x);
        }
        int s=0;
        queue<int> q; q.push(s);
        vector <int> color(n, INF); color[s]=0;
        bool isBipartite = true;
        while (!q.empty() && isBipartite){
            int u = q.front(); q.pop();
            for(auto &v: Al[u]){
                if(color[v]==INF) {color[v]=1-color[u]; q.push(v);}
                else if (color[v]==color[u]){isBipartite=false; break;}
            }
        }
        if(isBipartite) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    
}