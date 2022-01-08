#include <bits/stdc++.h>
using namespace std;
int n;
int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

vector<int> solucion = {1};

bool can_place(int x){
    //for(auto &s: solucion) cout << s << " ";
    //cout << "\n";
    for(auto &s: solucion)
        if(s == x && x != 1) return false;
    //cout << "possible prime is: " << x + solucion.back() << "\n";
    for(int i=0; i<11;++i){
        if(x+solucion.back()==primes[i]) {
            return true;
        }
    }
    return false;
}

void backtrack(){
    //cout << "n is: " << n << "\n";
    //cout << "size is: " << solucion.size() << "\n";
    if(solucion.size()==n){
        //cout << "posible solucion\n";
        if(can_place(1)){
            for(int k=0; k<n; ++k){
                if(k==n-1) cout << solucion[k] << "\n";
                else cout << solucion[k] << " ";
            }
            //cout << "Encontre solucion\n";
            return;
        }
    }

    for(int r=2; r<=n; ++r){
        //cout << "r is: " << r << "\n";
        if(can_place(r)){
            //cout << "in fact " << r << " with " << solucion.back() << " is prime\n";
            solucion.push_back(r);
            backtrack();
            solucion.pop_back();
        }
    }
}

int main(){
    int c=0;
    cin >> n;
    cout << "Case " << ++c << ":\n";
    backtrack();
    solucion.clear();
    while(cin >> n) {
        if(!cin.eof()) cout << "\n";
        solucion.push_back(1);
        cout << "Case " << ++c << ":\n";
        backtrack();
        solucion.clear();
    }
}