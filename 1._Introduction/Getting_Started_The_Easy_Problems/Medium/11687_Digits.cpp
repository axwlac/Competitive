#include <iostream>
using namespace std;

int main(){
    string s;
    while(cin>>s, s!="END"){
        int index=1;
        while(to_string(s.size())!= s){s = to_string(s.size()); index++;}
        cout << index << "\n";
    }
    return 0;
}