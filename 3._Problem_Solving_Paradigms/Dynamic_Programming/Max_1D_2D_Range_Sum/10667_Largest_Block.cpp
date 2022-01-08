#include <bits/stdc++.h>
using namespace std;
int A[110][110];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p, s, n, r1, c1, r2, c2;

	cin >> p;
	while(p--){
		cin >> s;		
        cin >> n;
        
        memset(A, 0, sizeof(A));
        while(n--) {
        cin >> r1 >> c1 >> r2 >>c2;
            --r1, --c1, --r2, --c2;
            for(int i = r1; i <= r2; ++i)
            for(int j = c1; j <= c2; ++j) A[i][j] = -100;
        }

        bool flag = true;
        for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            if(A[i][j]==0){A[i][j]=1 ;flag=false;} 
            if (j > 0) A[i][j] += A[i][j-1];
        }
        }

        if(flag) {
        cout<<"0\n"; continue; 
        }
        
        int maxSubRect = -127*100*100;
        for(int l = 0; l < s; ++l){
            for(int r = l; r < s; ++r){
                int subRect = 0;
                for(int row = 0; row < s; ++row) {
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