#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    while (cin>>s, s!="#"){
        string ns = s;
        if(next_permutation(ns.begin(),ns.begin()+ns.size())){
            next_permutation(s.begin(),s.begin()+s.size());
            cout << s << "\n";
        }
        else cout << "No Successor\n";
        
    }
    
}