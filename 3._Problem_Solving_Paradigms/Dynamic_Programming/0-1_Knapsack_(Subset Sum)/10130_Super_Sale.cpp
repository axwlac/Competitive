#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int V[1000];
int W[1000]; 
int dp[300];
int N, S;


void knapSack(int N){
  memset(dp, 0,sizeof(dp)); 

  for (int i = 0; i < N; ++i) {
      for(int j = S; j >= W[i]; --j) dp[j] = max(dp[j], V[i] + dp[j - W[i]]);
  }  
}

int main() {
  int t;
  int sum; 
  cin >> t;
  while(t--){
    sum=0; 
    int n; cin >> n;
    for(int i=0; i<n; ++i) cin >> V[i] >> W[i];
    int g; cin >> g;
    for(int i=0; i<g; ++i){
      cin >> S;
      knapSack(n);
      sum += dp[S];
    }
    cout << sum << "\n";
  }
  return 0; 
}