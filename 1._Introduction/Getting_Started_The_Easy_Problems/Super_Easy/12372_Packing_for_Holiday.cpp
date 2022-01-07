#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cajas, L, W, H, conta;
    cin >> cajas;
    conta = 0;
    while(cajas--){
        cin >> L >> W >> H;
        conta++;
        if(L <= 20 && W <= 20 && H <= 20 ) cout << "Case " << conta << ": " << "good" << "\n";
        else cout << "Case " << conta << ": " << "bad" << "\n";
    }
    return 0;
}