#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t, g=1;
    while(1){
        cin >> t;
        if(cin.eof()) break;
        else if(g>1) cout << "\n";
        string n,k;
        int s,a,b,c;
        s = t;
        map<string,int> persona;
        vector <string> v;
        while(t--){cin >> n; persona[n]=0; v.push_back(n);}
        while(s--){
            cin >> n;
            cin >> a;
            persona[n] -= a;
            cin >> b;
            c=b;
            if(c!=0) {persona[n] += a-(c*(a/c));}
            else persona[n] += a;
            while(b--){cin >> k; persona[k] += a/c;}
        }
        for(string i: v){cout << i << " " << persona[i] << "\n";} 
        g++;
    }
    return 0;
}