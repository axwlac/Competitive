#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets, maxi=1;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  int maxSizeSet(){return maxi;}
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
    if(setSize[y]>maxi){maxi=setSize[y];}
    --numSets;                                   // a union reduces numSets
  }
};

int main(){
    int t,f, index=1; string f1,f2;
    cin>>t;
    while (t--){
        map <string,int> join;
        UnionFind uf(200001);
        cin>>f;
        while (f--){
            cin>>f1>>f2;
            if(join.count(f1)==0){join[f1]=index++;}
            if(join.count(f2)==0){join[f2]=index++;}
            if(!uf.isSameSet(join[f1],join[f2])){
                uf.unionSet(join[f1],join[f2]);}
            cout <<uf.sizeOfSet(join[f2]) << "\n";
            
        }
    }
    
}