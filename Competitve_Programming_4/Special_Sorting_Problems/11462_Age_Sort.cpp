#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    while (cin>>n, n!=0){
        vector <int> v;
        while (n--){
            cin>>s; v.push_back(s);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size();++i){
            if(i==v.size()-1){cout << v[i];}
            else {cout << v[i] << " ";}
        }
        cout << "\n";
    }
}