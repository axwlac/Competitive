#include <iostream>
using namespace std;
using ll = long long;


int main(){
    string s;
    ll t, m, b=0;
    cin >> t;
    while(t--){
        cin >> s;
        if(s == "donate"){
            cin >> m;
            b = b + m;
        }
        else if(s == "report") cout << b << "\n";
    }

    return 0;
}