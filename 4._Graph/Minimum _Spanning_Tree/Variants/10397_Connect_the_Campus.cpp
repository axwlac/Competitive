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

struct building{
    int node;
    double x;
    double y;
};

struct edges{
    double pos;
    int node1;
    int node2;
};

bool order(edges &x, edges &y){
    return x.pos < y.pos;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    while(cin >> n){
        double cost = 0.0;
        UnionFind uf(n);
        vector <building> edificios;
        for(int k=0; k<n; ++k){
            building b;
            b.node = k;
            cin >> b.x >> b.y;
            edificios.push_back(b);
        }
        cin >> m;
        while(m--){
            int u,v;
            cin >> u >> v;
            u--; v--;
            uf.unionSet(u,v);
        }
        vector <edges> e;
        for(int i=0; i<n-1; ++i){
            for(int k=i+1; k<n; ++k){
                edges r;
                r.pos = sqrt(((edificios[k].x-edificios[i].x)*(edificios[k].x-edificios[i].x)) + ((edificios[k].y-edificios[i].y)*(edificios[k].y-edificios[i].y)));
                r.node1 = edificios[k].node;
                r.node2 = edificios[i].node;
                e.push_back(r);
            }
        }
        sort(e.begin(), e.end(), order);
        for(auto d: e){
            if(!uf.isSameSet(d.node1, d.node2)){
                uf.unionSet(d.node1, d.node2);
                cost += d.pos;
            }
            if(uf.numDisjointSets()==1) break;
        }
        cout << fixed << setprecision(2) <<cost << "\n";
    }
}