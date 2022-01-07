#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string p;
    char c0='o',c1='n',c2='e';
    cin >> n;
    while(n--){
        cin >> p;
        if(p.length() == 5) cout << 3 << "\n";
        else{
            if(c0==p[0]  && c1==p[1]){cout << 1 << "\n";}
            else if(c0==p[0]  && c2==p[2]){cout << 1 << "\n";}
            else if(c1==p[1]  && c2==p[2]){cout << 1 << "\n";}
            else cout << 2 << "\n";
    }
    }
}