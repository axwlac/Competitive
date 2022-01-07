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
    int t; cin>>t; cin.ignore();
    while (t--){
        string line;
        map <char, int> f;
        vector <pair<char, char>> v;
        while(getline(cin, line)){
            if(line[0]=='*'){
                getline(cin, line);
                int index=0;
                for(char c:line){
                    if(c!=','){f[c] = index++;}
                }
                break;
                }
            else {v.push_back({line[1],line[3]});}
        }
        int acorn=0;
        UnionFind uf(f.size());
        for(auto c:v){uf.unionSet(f[c.first],f[c.second]);}
        for(auto it: f){if(uf.sizeOfSet((it).second)==1) ++acorn;}
        cout << "There are " << uf.numDisjointSets()-acorn << " tree(s) and " << acorn << " acorn(s).\n";
    }
    
}