#include <bits/stdc++.h>
using namespace std;
enum {UNVISITED = -1, VISITED = -2};
vector <int> dfs_num;
vector <int> ts;
vector <vector<int>> AL;

void topsort(int u){
    dfs_num[u] = VISITED;
    for(int v : AL[u]){
        if(dfs_num[v]==UNVISITED) topsort(v);
    }
    ts.push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; 
    while (cin >> n >> m, (n||m)){
        dfs_num.assign(n,UNVISITED);
        ts.clear();
        AL.assign(n, vector <int> ());
        for(int k=0; k < m; ++k){
            int x,y;
            cin >> x >> y;
            AL[x-1].push_back(y-1);
        }
        for(int k=0; k < n; ++k){if(dfs_num[k]==  UNVISITED) topsort(k);}
        reverse(ts.begin(), ts.end());
        for(int i=0; i < n; ++i){
            if(i!=n-1) cout << ts[i]+1 << " ";
            else cout << ts[i]+1 << "\n";
        }
        AL.clear();
    }

}