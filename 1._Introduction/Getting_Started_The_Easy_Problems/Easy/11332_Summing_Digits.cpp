#include <iostream>
#include <string>
using namespace std;

string rec(string h){
    while(h.size()>1){
        int a=0;
        for(int i=0; i<h.size(); i++) a += (int) h[i] - 48;
        h = to_string(a);
    }
    return h;
}

int main(){
    string n;
    while(cin >> n , (n!="0")) cout << rec(n) << "\n" ;
}