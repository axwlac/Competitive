#include <iostream>
using namespace std;

int main(){
    int in=0, n, out=0, index,aux=1;
    while(cin >> n, (n || 0)){
        out = in = 0;
        while(n--){
            cin >> index;
            if(index==0) out++;
            else if(index > 0) in++;
        }
        cout << "Case " << aux << ": "<< in - out << "\n";
        aux++;
    }
}