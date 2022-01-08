#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;

int R, C;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(int r, int c, char c1, char c2){
    if((r < 0) || (r >= R)) return 0;
    if((c < 0) || (c >= C)) return 0;
    if (grid[r][c] != c1 ) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for(int d=0; d < 8; ++d){
        ans += floodfill(r+dr[d], c+dc[d], c1, c2);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while (cin >> n >> m , (n || m)){
        R=n; C=m;
        int cont=0;
        vector<char> v;
        char c;
        int index=0;
        while (index < n*m){
            cin>>c;
            index++;
            v.push_back(c);
            if(index%m == 0) {grid.push_back(v);
            v.clear();
            }
        }
        for(int i=0; i < n; ++i){
            for(int k=0; k < m; ++k){
                if(grid[i][k]=='@') {floodfill(i,k,'@','*'); cont++;}
            }
        }
        cout << cont << "\n";
        grid.clear();
    }
    
}