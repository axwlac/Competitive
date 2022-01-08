#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int V[105];
int dp[60005];
int N, S;


int knapSack(int N, int W){
  memset(dp, 0,sizeof(dp)); 

  for (int i = 0; i < N; ++i) {
      for(int j = W; j >= V[i]; --j) dp[j] = max(dp[j], V[i] + dp[j - V[i]]);
  }  
  return dp[W]; 
}

int main() {
  int t;
  int sum; 
  cin >> t;
  while(t--){
    cin >> N;
    sum=0; 
    for(int i=0; i<N; ++i) {
      cin >> V[i];
      
      sum+=V[i]; 
    }
    cout<<sum- 2*knapSack(N, sum/2 ) << "\n"; 
  }
  return 0; 
}