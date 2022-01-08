#include <bits/stdc++.h>
using namespace std;

int R,C;
char grid[101][101];

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};


int ff(int r, int c, char c1,char c2){
    if((r < 0) || (r >= R)) return 0;
    if((c < 0) || (c >= C)) return 0;
    if(grid[r][c] != c1) return 0;
    int ans=1;
    grid[r][c] = c2;
    for(int d=0; d<8; ++d){
        ans += ff(r+dr[d], c+dc[d], c1, c2);
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> R >> C, (R||C)){
        memset(grid,0, sizeof(grid));
        string line;
        for(int i=0; i<R; ++i){
            cin >> line;
            for(int j=0; j<C; ++j){
                grid[i][j] = line[j];
            }
        }
        int stars = 0;
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(grid[i][j]=='.') continue;
                if(ff(i, j, '*', '.') == 1) stars++;
            }
        }
        cout << stars << "\n";
    }
}