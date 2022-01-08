#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
    int A[110][110];
	while(cin >> n >> m, (n || m)) {
    bool flag = true;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin>>A[i][j];  
        if(A[i][j]==1) A[i][j] = -100;
        else{
          A[i][j]=1;
          flag=false; 
        } 
        if (j > 0) A[i][j] += A[i][j-1];
      }
    }

    if(flag) {
      cout<<"0\n"; continue; 
    }
    int maxSubRect = -127*100*100;
    for(int l = 0; l < m; ++l){
        for(int r = l; r < m; ++r){
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
  return 0;
}