#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int countries[20][20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    int Set = 0, c = 0;
    while (1){
        if(c > 0){
            cout << "\n";
        }
        ++c;
        for(int u = 0; u < 20; ++u){
            for(int v = 0; v < 20; ++v){
                countries[u][v] = INF;
            }
            countries[u][u] = 0;
        }


        int line; cin >> line;
        if(cin.eof())break;
        for(int i=0; i < line;++i){
            int r; cin >> r;
            countries[0][r-1] = 1;
            countries[r-1][0] = 1;
        }

        for(int i=1; i<19; ++i){
            int t ;cin >> t;
            while(t--){
                int x;cin >> x;
                countries[i][x-1] = 1;
                countries[x-1][i] = 1;
            }
        }
        int V = 20;
         for (int k = 0; k < V; ++k){
            for (int u = 0; u < V; ++u){
                for (int w = 0; w < V; ++w){
                    countries[u][w] = min(countries[u][w], countries[u][k]+countries[k][w]);
                }
            }
         }
        int n; cin >> n;
        cout << "Test Set #" << ++Set << "\n";
        while(n--){
            int a,b; cin >> a >> b;
            cout << setw(2) << right << a;
            cout << " to ";
            cout << setw(2) << right << b << ": ";
            cout << left << countries[a-1][b-1] << "\n";
        }
    }
    
}