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

struct coms{
    int x;
    int y;
    int w;
};

bool order(coms &a, coms &b){
    return a.w < b.w;
}

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        int cont = 0;
        cin >> n >> m;
        UnionFind uf(n);
        map <string, int> M;
        vector <coms> v;
        while(m--){
            coms e;
            string s,d;
            cin >> s >> d >> e.w;
            if(M.count(s)==0) M[s] = cont++;
            if(M.count(d)==0) M[d] = cont++;
            e.x = M[s]; e.y = M[d];
            v.push_back(e);
        }
        sort(v.begin(), v.end(), order);
        int cost= 0;
        for(auto &c: v){
            if(!uf.isSameSet(c.x, c.y)){
                uf.unionSet(c.x, c.y);
                cost += c.w;
            }
            if(uf.numDisjointSets()==1) break;
        }
        cout << cost << "\n";
        if(t) cout <<  "\n";        
    }
}