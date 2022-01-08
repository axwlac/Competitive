#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

enum{ UNVISITED = -1, VISITED = -2};

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited;
stack <int> St;
 
vector <vi> AL;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    dfsNumberCounter++;
    St.push(u);
    visited[u] = 1;
    for(auto &v : AL[u]){
        if(dfs_num[v]== UNVISITED) tarjanSCC(v);
        if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++numSCC;
        while(1){
            int v = St.top(); St.pop();
            visited[v] = 0;
            if(u == v) break;
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M;
    while(cin >> N >> M, (N||M)){
        dfs_num.assign(N, UNVISITED); dfs_low.assign(N,0); visited.assign(N, 0);
        AL.assign(N, vi());
        while(M--){
            int V, W, P;
            cin >> V >> W >> P;
            V--; W--;
            if(P==1){AL[V].push_back(W);}
            else{
                AL[V].push_back(W);
                AL[W].push_back(V);
            }
        }
        while(!St.empty()) St.pop();
        dfsNumberCounter = numSCC = 0;
        for(int u = 0; u < N; u++){
            if(dfs_num[u] == UNVISITED) tarjanSCC(u);
        }

        if(numSCC == 1) cout << "1\n";
        else cout << "0\n";
    }
}