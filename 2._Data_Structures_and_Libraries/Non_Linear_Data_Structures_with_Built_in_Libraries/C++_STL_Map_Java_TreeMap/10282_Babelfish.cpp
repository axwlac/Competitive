#include <bits/stdc++.h>
using namespace std;

int main(){
    string line, token1,token2, token;
    map <string,string> translate;
    while(getline(cin,line),line!=""){
        stringstream s(line);
        while(s >> token1 >> token2){translate[token2] = token1;}
    }
    // cin.ignore();
    while(cin>>line){

        if(translate[line]!="") cout << translate[line] << "\n";
        else cout << "eh\n";
    }
}