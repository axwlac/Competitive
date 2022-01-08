#include <bits/stdc++.h> 
using namespace std;

long long combi(long long n, long long k){
    long long C = 1;
    if(k > n-k) k = n - k;
    for(int i = 0; i < k;++i){
        C *= (n - i);
        C /= (1 + i);
    }
    return C;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, z;
    while (cin >> n >> k){
        vector <int> v(k);
        for(int i=0; i<k; ++i) cin >> v[i];
        long long res = 1;
        long long arriba = 0;
        for(auto i : v){
            arriba += i;
            res *= combi(arriba, i);
        }
        cout << res << "\n";
    }
}