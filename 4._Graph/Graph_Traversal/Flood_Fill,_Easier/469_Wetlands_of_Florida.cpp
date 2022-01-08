#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

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
    int T;
        cin >> T;
        string line;
        cin.ignore();
        while(T--) {
            while(1){
                getline(cin, line);
                if(line.empty()) continue;
                if(isdigit(line[0])) break;
                grid.push_back(line);
            }
            R = grid.size();
            C = grid[0].size();
            stringstream ss(line);
            int r, c;
            ss >> r;
            ss >> c;
            --r, --c;
            cout << floodfill(r, c , 'W', '.') << "\n";
            floodfill(r, c, '.', 'W');
            while(getline(cin, line)){
                if(line.empty()) break;
                stringstream ss(line);
                ss >> r;
                ss >> c;
                --r, --c;
                cout << floodfill(r ,c ,'W' , '.') << "\n";
                floodfill(r ,c ,'.' , 'W');
            }
            if(T) cout << "\n";
            grid.clear();
        }
}