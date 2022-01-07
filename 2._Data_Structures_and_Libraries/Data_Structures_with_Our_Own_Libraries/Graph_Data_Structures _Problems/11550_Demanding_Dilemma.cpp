#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t,n,m,s;
    cin>>t;
    while (t--){
        vector <vector<int>> v;
        map <pair<int,int>,int> poso;
        cin>>n>>m;
        if(m==0) cout<<"Yes\n";
        else{
        for(int i=0; i<n; ++i){
            vector <int> d;
            for(int k=0; k<m; ++k){
                cin>>s; d.push_back(s);
            }
            v.push_back(d);
        }
        int error=0;
        for(int i=0; i<m; ++i){
            int index=0,p=0,j=0,o=0;
            for(int k=0; k<n; ++k){
                if(v[k][i]==1 && o==0) {++index; p=k; ++o;}
                else if(v[k][i]==1 && o==1) {++index; j=k; ++o;}
                else if(v[k][i]==1) ++index;
            }
            if(index!=2) {++error; break;}
            pair<int,int> lol = {p,j};
            poso[lol]++;
        }
        if(error==0){
            for(auto &it: poso){
                if(it.second>1) {++error; break;}
            }
        }
        if(error>0) cout<<"No\n";
        else cout << "Yes\n";
        }
    }
    
}