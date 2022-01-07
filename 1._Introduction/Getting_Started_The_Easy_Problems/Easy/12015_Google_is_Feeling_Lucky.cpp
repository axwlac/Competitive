#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t,r,index=1;
    string s;
    cin >> t;
    while(t--){
        vector <int> v1;
        vector <string> v2;
        int aux=0;
        for(int i=0;i<10;i++){
            cin >> s;
            v2.push_back(s);
            cin >> r;
            v1.push_back(r);
            if(r>aux) aux = r;
            else continue;
        }
        cout << "Case #" << index << ":\n";
        for(int i=0;i<v1.size();i++) if(v1[i]==aux) cout << v2[i] << "\n";
        index++;
    }
}