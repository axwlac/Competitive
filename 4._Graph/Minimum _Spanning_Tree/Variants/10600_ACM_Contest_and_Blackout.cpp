#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

struct edges{
    int w;
    int node1;
    int node2;
    bool flag = true;
};

bool order(edges &x, edges &y){
    return x.w < y.w;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        vector <edges> v;
        for(int i=0; i<m; ++i){
            edges e;
            cin >> e.node1 >> e.node2 >> e.w;
            e.node1--; e.node2--;
            v.push_back(e);
        }
        sort(v.begin(),v.end(), order);
        vector <int> costs;
        int co=0;
        vector <int> index;
        UnionFind uf(n);
        for(int d=0;  d < m; ++d){
            if(!uf.isSameSet(v[d].node1,v[d].node2)){
                uf.unionSet(v[d].node1,v[d].node2);
                co += v[d].w;
                index.push_back(d);
            }
            if(uf.numDisjointSets()==1) break;
        }
        costs.push_back(co);
        for(int i: index){
            UnionFind UF(n);
            int c=0; bool complete = false;
            for(int k=0; k < m; ++k){
                if( !UF.isSameSet(v[k].node1, v[k].node2) && k!=i){
                    UF.unionSet(v[k].node1, v[k].node2);
                    c += v[k].w;
                }
                if(UF.numDisjointSets()==1) {complete = true; break;}
            }
            if(complete) costs.push_back(c);
        }
        sort(costs.begin(), costs.end());
        cout << costs[0] << " " << costs[1] <<"\n";
    }
    
}