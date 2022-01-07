#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t,index=0;
    cin>>t;
    while(t--){
        if(index++>0) cout << "\n";
        int w;
        vector <int> v;
        cin >> w;
        while(w--){
            int a,b;
            cin >> a >> b;
            v.push_back(abs(a-b));
        }
        sort(v.begin(),v.end());
        if(v[0]==v[v.size()-1]) cout << "yes\n"; 
        else cout << "no\n";
    }
}