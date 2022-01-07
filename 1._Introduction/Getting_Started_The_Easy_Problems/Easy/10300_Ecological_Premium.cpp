#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n,f,tot=0,a,b,c;
    cin >> n;
    while(n--){
        cin >> f;
        while(f--){
            cin >> a >> b >> c;
            tot = tot + (a*c);
        }
        cout << tot << "\n";
        tot=0;
    }
    return 0;
}