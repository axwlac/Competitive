#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main(){
    int n,m,i,k,v,index=1;
    vector <vi> vec(1000001,vi());
    while(cin>>n>>m){
        set <int> S;
        while(n--){
            cin>>i;
            S.insert(i);
            vec[i].push_back(index++);
        }
        while(m--){
            cin>>k>>v;
            if(vec[v].size()>=k){cout << vec[v][k-1] << "\n";}
            else {cout << "0\n";}
        }
        for(auto &s:S){vec[s].clear();}
        index=1;
    }
}