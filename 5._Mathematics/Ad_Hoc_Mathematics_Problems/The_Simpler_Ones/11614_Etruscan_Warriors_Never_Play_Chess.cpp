#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//ver numeros triangulares
int main(){
    int t; cin>>t;
    long long int w;
    while(t--){
        cin>>w;
        if(w==0) cout<< 0<<"\n";
        else cout << fixed << setprecision(0) << floor((-1+sqrt(1+(8*w)))/2) << "\n";
    }
}