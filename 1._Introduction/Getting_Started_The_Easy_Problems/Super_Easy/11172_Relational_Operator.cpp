#include <iostream>
using namespace std;
 
int main(){
    int a , x, y ;
    cin >> a ;
    while(a--){
        cin >> x >> y;
            if(x < y) cout << "<\n";
            else if(x > y) cout << ">\n";
            else cout << "=\n";
            
    }
    return 0;
}