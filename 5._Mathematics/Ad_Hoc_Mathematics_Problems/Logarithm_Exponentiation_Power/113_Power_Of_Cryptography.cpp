#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    long double p, n;
    while(cin >> n >> p){
        cout << fixed <<setprecision(0) << exp(log(p)/n) << "\n";
    }
    return 0;
}