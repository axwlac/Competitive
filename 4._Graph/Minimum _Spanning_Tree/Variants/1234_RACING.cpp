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

struct aristas{
    int x;
    int y;
    int w;
};

bool order(aristas &x, aristas&y){
    return x.w > y.w;
}

int main(){
    int c;
    cin >> c;
    while (c--){
        int n,m,total=0,cost=0;
        cin >> n >> m;
        UnionFind uf(n);
        vector <aristas> v;
        while (m--){
            aristas a;
            cin >> a.x >> a.y >> a.w;
            total += a.w;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), order);
        for(auto s: v){
            if(!uf.isSameSet(s.x-1, s.y-1)){
                uf.unionSet(s.x-1, s.y-1);
                cost += s.w;
            }
            if(uf.numDisjointSets()==1) break;
        }
        cout << total-cost << "\n";
    }
    
}