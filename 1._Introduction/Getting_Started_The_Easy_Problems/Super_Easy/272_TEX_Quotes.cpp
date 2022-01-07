//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main () {

    char c;
    int a = 1;
    while(cin.get(c)) {
        if((c == '"') && (a % 2 == 1)) 
            cout << '`'  << '`', a++;
        else if((c == '"') && (a % 2 == 0))
             cout << '\''  << '\'', a++;
        else cout << c;
        
    }
    return 0;
}