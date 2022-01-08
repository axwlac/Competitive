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

struct vertex{
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n,m;
        cin >> n;
        UnionFind uf(n);
        vector <vertex> v;
        for(int i=0; i < n; ++i){
            vertex ver;
            cin >> ver.x >> ver.y ;
            ver.node=i;
            v.push_back(ver);
        }
        cin >> m;
        while (m--){
            int x,y;
            cin >> x >> y;
            uf.unionSet(x-1,y-1);
        }
        vector <edges> e;
        for(int i=0 ; i < n-1; ++i){
            for(int k=i+1; k < n ; ++k){
                edges r;
                r.pos = sqrt(((v[k].x-v[i].x)*(v[k].x-v[i].x)) + ((v[k].y-v[i].y)*(v[k].y-v[i].y)));
                r.node1 = v[k].node;
                r.node2 = v[i].node;
                e.push_back(r);            
            }
        }
        sort(e.begin(), e.end(), order);
        if(uf.numDisjointSets()==1) cout << "No new highways need\n";
        else{
            for(auto d: e){
                if(!uf.isSameSet(d.node1, d.node2)){
                    uf.unionSet(d.node1, d.node2);
                    cout << d.node2+1 << " " << d.node1+1 << "\n";
                }
                if(uf.numDisjointSets()==1) break;
            }
        }

        if(t) cout << "\n";
    }
    return 0;
}