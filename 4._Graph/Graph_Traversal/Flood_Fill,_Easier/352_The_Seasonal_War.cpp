#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int R,C;
char photo[25][25];

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int ff(int r, int c, char c1,char c2){
    if((r < 0) || (r >= R)) return 0;
    if((c < 0) || (c >= C)) return 0;
    if(photo[r][c] != c1) return 0;
    int ans=1;
    photo[r][c] = c2;
    for(int d=0; d<8; ++d){
        ans += ff(r+dr[d], c+dc[d], c1, c2);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int dim, ImageNumber=1;
    while(cin >> dim){
        R=dim; C=dim;
        memset(photo,0, sizeof(photo));
        string line;
        for(int i=0; i<dim; ++i){
            cin >> line;
            for(int j=0; j<dim; ++j){
                photo[i][j] = line[j];
            }
        }
        int eagles=0;
        for(int i=0; i<dim; ++i){
            for(int j=0; j<dim; ++j){
                if(photo[i][j] == '0') continue;
                bool yes = (ff(i, j, '1', '0') > 0);
                eagles += yes;
            }
        }
        cout << "Image number " << ImageNumber++ << " contains " << eagles << " war eagles.\n";
    }
}