#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first*b.second< a.second*b.first) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> x;
    while(cin >> x.first >> x.second, !(x.first==1 && x.second==1) ){
        pair <int,int> l ={0,1}, r={1,0};
        string steps = "";
        while(1){
            pair <int,int> m = {l.first+r.first, l.second+r.second};
            if(x == m) break;
            if(comp(x, m) ) {
                r = m; 
                steps += 'L';
            }
            else {
                l = m; 
                steps += 'R';
            }
        }
        cout << steps << "\n";
    }
}