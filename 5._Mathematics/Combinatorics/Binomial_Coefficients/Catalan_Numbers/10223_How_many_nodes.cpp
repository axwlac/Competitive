#include <bits/stdc++.h> 
using namespace std;

long long combinations(long long n, long long k){
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
    vector <long long> Cat(20,0);
    for(int k=1; k < 20; ++k) Cat[k] = combinations(2*k,k)/(k+1);
    int n; 
    while (cin >> n){
        int aux;
        for(int k=0; k < 20; ++k){
            if(Cat[k]==n){
                aux = k;
                break;
            }
        }
        cout << aux << "\n";
    }
    
}