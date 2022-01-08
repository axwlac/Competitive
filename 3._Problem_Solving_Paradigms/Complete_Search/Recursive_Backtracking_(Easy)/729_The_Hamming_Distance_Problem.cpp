#include <bits/stdc++.h>
using namespace std;
int t,n,h;
int sum=0;
vector <int> v;
vector <string> sv;
bool CanPlace(int &x){
    if(sum+1<=h && v[x]!=1) return true;
    return false;
}

void bt(int pos){
    if(sum==h){
        string s = "";
        for(int l : v) s += to_string(l);
        sv.push_back(s);
    }

    for(int k=pos; k<n; ++k){
        if(CanPlace(k)){
            v[k]=1;
            sum++;
            bt(k+1);
            v[k]=0;
            sum--;
        }
    }
}

int main(){
    cin >> t;
    while (t--){
        cin >> n >> h;
        for(int o=0; o<n; ++o) v.push_back(0);
        bt(0);
        sort(sv.begin(), sv.end());
        for(int p=0; p<sv.size(); ++p){
            cout << sv[p] << "\n";
        }
        v.clear();
        sv.clear();
        if(t) cout << "\n";
    }
    
}