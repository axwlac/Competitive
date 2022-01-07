#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t,s;
    while(cin>>t, t!=0){
        vector <int> v;
        int y=0;
        while(t--){cin>>s; v.push_back(s);}
        sort(v.begin(), v.end());
        vector <int> h,g; h=v;
        sort(h.rbegin(), h.rend());       
        for(int i=0; i<h.size();i++) v.push_back(1422+1422-h[i]);
        for(int i=0; i<v.size()-1;i++){
            // cout << v[i] << "\n";
            if(abs(v[i]-v[i+1])>200) y++;
            } 

        if(y>0) cout << "IMPOSSIBLE\n";
        else cout << "POSSIBLE\n";
    }
}