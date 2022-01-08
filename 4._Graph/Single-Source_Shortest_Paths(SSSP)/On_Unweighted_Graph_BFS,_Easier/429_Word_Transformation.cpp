#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while (n--){
        vector <string> S;
        map <string, int> M;
        string s, line;
        int index = 0;
        while (cin >> s, s!="*"){
            S.push_back(s);
            M[s] = index++;
        }
        int V = S.size();
        vector <vector<int>> Al(V, vector<int> ());
        int Size  = S[0].size();
        for(int k=0; k < S.size()-1; ++k){
            for(int i = k + 1; i < S.size() ; ++i){
                int cmp=0; 
                for(int j=0; j < Size; ++j){if(S[k][j]!=S[i][j]) cmp++;}
                if(cmp==1){
                    Al[M[S[i]]].push_back(M[S[k]]);
                    Al[M[S[k]]].push_back(M[S[i]]);
                }
            }
        }
        cin.ignore();
        while (getline(cin, line), line!=""){
            stringstream ss(line);
            string w1, w2;
            ss >> w1 >> w2;
            cout << w1 << " " << w2 << " ";
            vector <int> d(V, INF); d[M[w1]] = 0; 
            queue <int> q; q.push(M[w1]);
            while (!q.empty()){
                int u = q.front(); q.pop();
                if(u == M[w2]) break;
                for(auto &v: Al[u]){
                    if(d[v] != INF) continue;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
            cout << d[M[w2]] << "\n";
        }
        if(n) cout << "\n";
    }
    

    return 0;
}