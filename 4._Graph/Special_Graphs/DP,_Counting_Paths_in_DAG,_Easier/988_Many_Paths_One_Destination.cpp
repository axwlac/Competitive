#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Al;
vector<int> ts;
enum {UNVISITED = 0, VISITED = 1};
vector<int> dfs_num;
vector<int> dist;
const int INF = 1e9;

void toposort(int u) {
  dfs_num[u] = VISITED;
  for (int v : Al[u]){
    if (dfs_num[v] == UNVISITED)
      toposort(v);
  }
  ts.push_back(u);                               
}

int main(){
    int ne,c=0;
    while (cin >> ne){

        dfs_num.clear();
        dist.clear();
        ts.clear();
        Al.clear();

        dfs_num.assign(ne,UNVISITED);
        if(c>0) cout << "\n";
        c++;
        Al.assign(ne, vector <int> ());
        int V = ne;
        vector <int> F;
        int n,node; 
        for(int index=0; index < V; ++index){
            cin >> n;
            if(n==0) F.push_back(index);
            for(int i=0; i<n; ++i){
                cin >> node; Al[index].push_back(node);
            }
        }
        for (int u = 0; u < V; ++u) {if (dfs_num[u] == UNVISITED) toposort(u);}
        reverse(ts.begin(), ts.end());
        vector<int> num_paths(V,0); num_paths[0] = 1;
        for(int i = 0; i < V; ++i){
            int u = ts[i];
            for(int v: Al[u]){num_paths[v] += num_paths[u];}
        }
        int tot=0;
        for(auto s: F){tot += num_paths[s];}
        cout << tot << "\n";
    }
}