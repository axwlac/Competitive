#include <iostream>
using namespace std;
//POR MANDAR

int main(){
    string s;
    int i=1;
    while(cin >> s){
        if(s == "Hajj") cout << "Case " << i << ": Hajj-e-Akbar\n";
        else if(s == "Umrah") cout << "Case " << i << ": Hajj-e-Asghar\n";
        else if(s == "*") break;
        i++;
    }
    return 0;
}