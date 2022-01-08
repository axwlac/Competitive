#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K;
ll dp[200][200];
ll ways(int n, int k){
    if(dp[n][k]!=0) return dp[n][k];
    if(k==1) return 1;
    ll res = 0;
    for(int i=0; i<=n; i++){
        res = (res % 1000000 +  ways(i, k-1)%1000000 )%1000000;
    }
    return dp[n][k] = res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N >> K, (N||K)){
        cout << ways(N,K) << "\n";
    }
}