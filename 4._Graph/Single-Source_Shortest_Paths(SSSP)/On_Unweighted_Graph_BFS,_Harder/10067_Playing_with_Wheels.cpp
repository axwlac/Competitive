#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
const int INF = 1e9;

int modulo(int i, int n) {
    return (i % n + n) % n;
}

bool can[10000] = {true};

vi desc(int f){
    vi d(4);
    int ind=3;
    while(f>=10){
        int digit = f%10;
        d[ind] = digit;
        ind --;
        f /= 10;
    }
    d[ind] = f;
    return d;
}

vi vecinos(int x){
    vi neig;
    vi parts = desc(x);
    for(int k=0; k<4; ++k){
        int aux = 0, ten = 1000;
        for(int num=0 ; num<4; num++){
            if(num==k) aux += modulo(parts[num]+1,10) * ten;
            else{
                aux += parts[num]*ten;
            }
            ten /= 10;
        }
        neig.push_back(aux);
        aux = 0, ten = 1000;
        for(int num=0 ; num<4; num++){
            if(num==k) aux += modulo(parts[num]-1,10) * ten;
            else{
                aux += parts[num]*ten;
            }
            ten /= 10;
        }
        neig.push_back(aux);
    }
    return neig;

}

int main(){
    int t; cin >> t;
    while(t--){
        memset(can, true, sizeof(can));
        int ini=0,des=0, h, forbidden, n;
        for(int i=3; i>=0; --i) {
            cin >> h;
            if(i==3) h *= 1000;
            if(i==2) h *= 100;
            if(i==1) h *= 10;
            ini += h;
        }
        for(int i=3; i>=0; --i) {
            cin >> h;
            if(i==3) h *= 1000;
            if(i==2) h *= 100;
            if(i==1) h *= 10;
            des += h;
        }
        cin >> n;
        while(n--){
            forbidden =0;
            for(int i=3; i>=0; --i) {
                cin >> h;
                if(i==3) h *= 1000;
                if(i==2) h *= 100;
                if(i==1) h *= 10;
                forbidden += h;
            }
            can[forbidden] = false;
        }
        vi dist(10000, INF); dist[ini] = 0;
        bool reached = false;
        queue<int> q; q.push(ini);
        while (!q.empty() || reached){
            int u = q.front(); q.pop();
            if(u == des) {reached=true;break;}
            for(auto v: vecinos(u)){
                if(dist[v]!=INF) continue;
                if(can[v]==false) continue;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
        if(reached) cout << dist[des] << "\n";
        else cout << "-1\n";
    }
}