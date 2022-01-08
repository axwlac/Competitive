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
    int n; cin >> n;
    while (n--){
        int s,p;
        cin >> s >> p;
        UnionFind uf(p);
        vector <vertex> v;
        for(int i=0; i < p; ++i){
            vertex ver; ver.node = i;
            cin >> ver.x >> ver.y;
            v.push_back(ver);
        }
        vector <edges> e;
        for(int i=0 ; i < p-1; ++i){
            for(int k=i+1; k < p ; ++k){
                edges r;
                r.pos = sqrt(((v[k].x-v[i].x)*(v[k].x-v[i].x)) + ((v[k].y-v[i].y)*(v[k].y-v[i].y)));
                r.node1 = v[k].node;
                r.node2 = v[i].node;
                e.push_back(r);            
            }
        }
        sort(e.begin(), e.end(), order);
        double cost = 0;
        for(auto d: e){
            if(uf.numDisjointSets()==s) break;
            if(!uf.isSameSet(d.node1, d.node2)){
                uf.unionSet(d.node1, d.node2);
                cost = max(cost, d.pos); 
            }
        }
        cout << fixed << setprecision(2) <<cost << "\n";
    }   
}