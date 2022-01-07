#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,B,H,W,p,Wp;
    while(cin >> N >> B >> H >> W){
        vector <int> v;
        int aux = W;
        while(H--){
            cin >> p;
            while(W--) {
                cin >> Wp;
                if(Wp >= N)v.push_back(p*N);
                else continue;
                }
            W = aux;
        }
        sort(v.begin(),v.end());
        if(v[0] > B || v.empty()) cout << "stay home\n";
        else cout << v[0] << "\n";
    }
}