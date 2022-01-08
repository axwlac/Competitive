#include <bits/stdc++.h>
using namespace std;

int R,C;
char grid[25][25];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

int ff(int r, int c, char c1,char c2){
    if((r < 0) || (r >= R)) return 0;
    if((c < 0) || (c >= C)) return 0;
    if(grid[r][c] != c1) return 0;
    int ans=1;
    grid[r][c] = c2;
    for(int d=0; d<4; ++d){
        ans += ff(r+dr[d], c+dc[d], c1, c2);
    }
    return ans;
}

struct xo{
    int no;
    char key;
};

bool order(xo &a, xo &b){
    if(a.no!=b.no) return a.no > b.no;
    return a.key < b.key;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int k=1; k<=n; ++k){
        cout << "World #" << k << "\n";
        int H,W;
        cin >> H >> W;
        R=H; C=W;
        map <char, int> region;
        memset(grid,0, sizeof(grid));
        string line;
        for(int i=0; i<H; ++i){
            cin >> line;
            for(int j=0; j<W; ++j){
                grid[i][j] = line[j];
            }
        }

        for(int i=0; i<H; ++i){
            for(int j=0; j<W; ++j){
                if(grid[i][j]=='X') continue;
                region[grid[i][j]] += 1;
                ff(i, j, grid[i][j], 'X');
            }
        }
        vector<xo> res;
        for(auto x: region){
            xo y;
            y.key = x.first; y.no = x.second;
            res.push_back(y);
        }
        sort(res.begin(), res.end(), order);
        for(auto o: res) cout << o.key << ": " << o.no << "\n";
    }
}