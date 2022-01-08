#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi match, vis;                                   // global variables
vector<vi> AL;

int Aug(int L) {
  if (vis[L]) return 0;                          // L visited, return 0
  vis[L] = 1;
  for (auto &R : AL[L])
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      return 1;                                  // found 1 matching
    }
  return 0;                                      // no matching
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int  k=1 ; k<=T; ++k){
        cout << "Case " << k << ": a maximum of "; 
        int bolts, nuts;
        cin >> bolts >> nuts;
        int V  = bolts + nuts;
        AL.assign(V, {});
        int edge;
        for(int  u = 0; u < bolts; ++u){
            for(int v = bolts; v < V; ++v ){
                cin >> edge;
                if(edge == 1) AL[u].push_back(v);
            }
        }
        unordered_set<int> free_vertex;
        int left_vertex = bolts;
        for (int L = 0; L < bolts; ++L) free_vertex.insert(L);
        match.assign(V, -1);
        int MCBM = 0;
        for(auto x:free_vertex){
            vis.assign(bolts, 0);
            MCBM += Aug(x);
        }


        cout << MCBM <<" nuts and bolts can be fitted together\n";
    }
}