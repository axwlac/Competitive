#include <bits/stdc++.h> 
using namespace std;

long long mod(long long a, long long m){ return ((a % m)+m)%m;}

long long modPow(long long b, long long p, long long m){
    if(p==0) return 1;
    long long ans = modPow(b, p/2, m);
    ans = mod(ans*ans, m);
    if(p&1) ans = mod(ans*b, m);
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long B, P, M;
    while(cin >> B >> P >> M){
        cout << modPow(B, P, M) << "\n";
    }
}