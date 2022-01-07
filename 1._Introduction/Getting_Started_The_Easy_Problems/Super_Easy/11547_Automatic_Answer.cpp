#include <iostream>
using namespace std;

int main(){
    int t,n,f;
    string s="";
    cin >> t;
    while(t--){
        cin >> n;
        f = (((((n*567)/9)+7492)*235)/47)-498;
        s =  to_string(f);
        cout << s[s.length()-2] << "\n";
    }
    return 0;
}