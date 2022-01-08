#include <bits/stdc++.h>
using namespace std;

 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; 
  int A[101][101];
  bool flag; 
  int menNeg = -127*100*100; 
  while(cin >> n){
      menNeg= -127*100*100;
      flag=true; 
   for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            cin >> A[i][j];

            if(A[i][j]>0) flag=false; 
            if(menNeg<A[i][j]) menNeg = A[i][j]; 
            if (j > 0) A[i][j] += A[i][j-1];
            
        }

    if(flag){
        cout<<menNeg<<"\n"; 
        continue; 
    }
    int maxSubRect = -127*100*100;
    for(int l = 0; l < n; ++l){
        for(int r = l; r < n; ++r){
            int subRect = 0;
            for(int row = 0; row < n; ++row) {
                // Max 1D Range Sum on columns of this row
                if (l > 0) subRect += A[row][r] - A[row][l-1];
                else subRect += A[row][r];
                // Kadane's algorithms on rows
                 if (subRect < 0) subRect = 0;
                maxSubRect = max(maxSubRect, subRect);
            }
        }
    }

    cout<<maxSubRect<<"\n"; 
  }
}