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
    int n, m=0;
    while (cin >> n){
        if(m > 0) cout << "\n";
        m++;
        cout << combinations(2*n,n)/(n+1) << "\n";
    }
}