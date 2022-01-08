#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;


int main(){
    int N, M, B, P;
    while(cin >> N >> M >> B >> P){
        vector<vii> Al(N, vii ());
        // vector<bool> visited(N,false);
        for(int i=0; i < M; ++i){
            int U,V,T;
            cin >> U >> V >> T;
            Al[U].push_back({V,T});
            Al[V].push_back({U,T});
            // visited[U]=true;visited[V]=true;
        }
        vector <int> Banks(B);
        for(int i=0; i<B; ++i){cin >> Banks[i];}
        vector <int> Police(P);
        for(int i=0; i<P; ++i){cin >> Police[i];}
        if(P==0){
            cout << B << " *\n" ;
            sort(Banks.begin(),Banks.end());
            for(int i=0; i < B-1; ++i){
                cout << Banks[i] << " ";
            }
            cout << Banks[B-1] << "\n";
        }
        else{
            vii S0;
            for(int i=0; i < P; ++i){
                Al[Police[i]].push_back({N,0});
                S0.push_back({Police[i],0});
            }
            Al.push_back(S0);
            vi dist(N+1, INF); dist[N]=0;
            priority_queue<ii, vector<ii>, greater<ii>> pq;
            for(int u=0; u < N+1 ; ++u){pq.emplace(dist[u], u);}
            while(!pq.empty()){
                auto p = pq.top(); pq.pop();
                int d = p.first, u = p.second;
            if(d > dist[u]) continue;
                for(auto x: Al[u]){
                    int v = x.first, w = x.second;
                    if(dist[u] + w >= dist[v]) continue;
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
            vii bd;
            vector <int> ift;
            int maxi=0, infty=0;
            for(auto b: Banks){
                if(dist[b]>maxi && dist[b]!=INF) maxi=dist[b];
                if(dist[b]==INF){infty++; ift.push_back(b);}
                if(dist[b]!=INF) bd.push_back({b,dist[b]});
            }
            sort(bd.begin(),bd.end());
            if(infty){
                cout << infty << " *\n";
                sort(ift.begin(),ift.end());
                for(int i=0; i<ift.size()-1; ++i){
                    cout << ift[i] << " ";
                }
                cout << ift[ift.size()-1] << "\n";
            }
            else{
                int c=0;
                vector <bool> bo;
                for(int i=0; i < B; ++i){
                    if(maxi==bd[i].second) c++;
                }
                cout << c << " " << maxi << "\n";
                int cp=c-1; 
                for(int i=0; i < B; ++i){
                    if(maxi==bd[i].second){
                        cout << bd[i].first;
                        if(cp==0) cout << "\n";
                        if(cp) {cout << " "; cp--;}
                    }
                }
            }
        }
    }
}