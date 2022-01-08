#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vii;
typedef vector<int> vi;

enum { UNVISITED = -1 };
// these variables have to be global to be easily accessible by our recursion (other ways exist)
vector<vii> AL;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
  dfs_low[u] =  dfsNumberCounter++;
  dfs_num[u] = dfsNumberCounter++;  // dfs_low[u]<=dfs_num[u]
  for (auto &v : AL[u]) {
    if (dfs_num[v] == UNVISITED) {               // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) ++rootChildren;          // special case, root

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u]) {articulation_vertex[u] = 1;}
      dfs_low[u] = min(dfs_low[u], dfs_low[v]); 

    }
    else if (v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V;
    while(cin >> V, V){
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
        dfs_parent.assign(V, -1); articulation_vertex.assign(V, 0);
        dfsNumberCounter = 0;
        AL.assign(V, vector<int>());
        cin.ignore();
        string line;
        while(getline(cin, line)) {
            int u, v;
            if(line == "0") break;
            stringstream ss(line);
            ss >> v;
            --v;
            while(ss >> u){
                --u;
                AL[u].emplace_back(v);
                AL[v].emplace_back(u);
            }
        }
        int c=0;
        for(int i =0;i < V; ++i){
            if(dfs_num[i]==UNVISITED){
                dfsRoot=i; rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        for (int u = 0; u < V; ++u) if (articulation_vertex[u]) c++;
        cout << c<< "\n"; 
    }
}