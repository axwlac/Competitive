#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string type;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        int total_types=0;
        map <string,int> tree;
        while(true){
            getline(cin, type);
            if(type.size()==0){
                for(auto& m: tree) {cout << fixed << setprecision(4) << m.first << " " << (100*(double)m.second)/(total_types) << "\n";}
                break;
            }
            else{
                total_types++;
                tree[type]++;
            }
        }
        if(t>0) cout << "\n";
    }
}