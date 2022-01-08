#include <bits/stdc++.h>
using namespace std;
int A[30][30];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T; cin >> T;
    cin.ignore();
    while(T--){
        string s;
        cin >> s;
		int n = s.size();
		memset(A, 0, sizeof(A));
		for(int j = 0; j < n; ++j) {
			A[0][j] = s[j] - '0';
            if(A[0][j]==0) A[0][j] = -100;
			if (j > 0) A[0][j] += A[0][j-1];

		}
		for(int i = 1; i < n; ++i){
			cin >> s;
			for(int j = 0; j < n; ++j) {
				A[i][j] = s[j] - '0';
                if(A[i][j]==0) A[i][j] = -100;
				if (j > 0) A[i][j] += A[i][j-1];
			}
		}
        // cout << "Copy\n";
        // for(int k=0; k<u; k++){
        //     for(int l=0; l<n; ++l){
        //         cout << A[k][l] << " ";
        //     }
        //     cout << "\n";
        // }

        // if(ok){cout<<"0\n"; continue;}
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
        if(T) cout << "\n";
        // cin.ignore();
    }
}