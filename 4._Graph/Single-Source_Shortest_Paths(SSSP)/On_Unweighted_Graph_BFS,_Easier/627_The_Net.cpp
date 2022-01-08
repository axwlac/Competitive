#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> p;
int n1, n2;

void printPath(int u) {
    if (p[u] == -1) {
        cout << u + 1;
        return;
    }
    printPath(p[u]);                              
    cout << " " <<  u + 1;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V;
    while(cin >> V) {
        if(cin.eof()) break;
        cout << "-----\n";
        vector<vector<int>> AL(V, vector<int>());
        cin.ignore();
        string line;
        for(int i = 0 ; i < V; ++i){
            getline(cin , line);
            replace(line.begin(), line.end(), '-', ' ');
            replace(line.begin(), line.end(), ',', ' ');
            stringstream ss(line);
            int u;
            string f;
            ss >> u;
            ss >> f;
            if(f.size() == 0) continue;
            int v = stoi(f);
            --u;--v;
            AL[u].emplace_back(v);
            while(ss >> v){
                --v;
                AL[u].emplace_back(v);
            } 
        }   
        int m; cin >> m;
        for (int i=0; i < m; ++i){
            // cout << "here!\n";
            cin >> n1 >> n2;
            n1--; n2--;
            p.clear();
            p.assign(V,-1);
            vector <int> dist(V, INF); dist[n1]=0;
            queue<int> q; q.push(n1);
            while (!q.empty()){
                int u = q.front(); q.pop();
                if(u==n2) break;
                for(auto &vi: AL[u]){
                    if(dist[vi] != INF) continue;
                    dist[vi] = dist[u] + 1;
                    p[vi] = u;
                    q.push(vi);
                }
            }
            if(dist[n2] != INF) {printPath(n2); cout << "\n";}
            else {cout << "connection impossible\n";}
        }
    }
}