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
    return x.w < y.w;
}

main(){
    int n; bool first = false;
    while(cin >> n){
        if(first) cout << "\n";
        first = true;
        int k, m, costo=0; 
        UnionFind uft(n);
        vector <aristas> todos;
        for (int i=0; i< n-1; ++i){
            aristas a;
            cin >> a.x >> a.y >> a.w;
            costo +=  a.w;
            todos.push_back(a);
        }
        cin >> k;
        for(int i =0; i < k; ++i){
            aristas a;
            cin >> a.x >> a.y >> a.w;
            todos.push_back(a);
        }
        cin >> m;
        for(int i =0; i < m; ++i){
            aristas a;
            cin >> a.x >> a.y >> a.w;
        }
        int costt=0;
        sort(todos.begin(), todos.end(), order);
        for(auto j : todos){
            if(!uft.isSameSet(j.x-1,j.y-1)){
                uft.unionSet(j.x-1,j.y-1);
                costt += j.w;
            }
            if(uft.numDisjointSets()==1) break;
        }
        cout << costo << "\n" << costt << "\n";
    }
}