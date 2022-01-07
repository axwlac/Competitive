#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int t,index=1;
    float c,d,aux, aux2;
    cin >> t;
    while(t--){
        
        cin >> c >> d;
        aux = (c*9/5) + 32 + d + 0.000;
        aux2 = (aux-32)*5/9 + 0.000;
        cout << "Case " << index << ": " << fixed << setprecision(2) << aux2 << "\n";
        index++;
    }

    return 0;
}