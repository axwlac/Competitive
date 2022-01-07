#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t,n,s,i=1, s0,s1;
    cin >> t;
    while(t--){
        cin >> n;
        s0=n;
        while(n--){
            cin >> s;
            if(ceil(s0/2)==n) s1=s;
        }
        cout << "Case " << i << ": " << s1 << "\n";
        i++;

    }
    return 0;
}