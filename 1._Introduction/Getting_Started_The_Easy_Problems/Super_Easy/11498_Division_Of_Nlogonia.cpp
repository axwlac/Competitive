#include <iostream>
using namespace std;

int main(){
    int k, x0, y0, x1, y1;
    while(cin >> k, (k || 0)){
        cin >> x0 >> y0;
        while(k--){
            cin >> x1 >> y1;
            if(x1==x0 || y1==y0){cout << "divisa\n";}
            else if(x1>x0 && y1>y0){cout << "NE\n";}
            else if(x1<x0 && y1>y0){cout << "NO\n";}
            else if(x1>x0 && y1<y0){cout << "SE\n";}
            else if(x1<x0 && y1<y0){cout << "SO\n";}
        }
    }
}