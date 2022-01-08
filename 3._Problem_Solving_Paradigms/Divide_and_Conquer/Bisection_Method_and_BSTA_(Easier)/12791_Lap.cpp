#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    double x,y;    
    while(cin >> x >> y){
        cout << ceil(y/(y-x)) << "\n";
    }
}