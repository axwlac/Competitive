#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t , n ,m, r, c;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        r =  floor(m/3);
        c = floor(n/3);
        cout << r*c << "\n";
    }
    return 0;
}