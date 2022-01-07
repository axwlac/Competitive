#include <iostream>

using namespace std;

long gcd(long a, long b, long & x, long & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long x1, y1;
    long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long a,b,x,y,d;
    while(cin >> a >> b){
        d = gcd(a,b,x,y);
        if(a == 0 && b==0) cout << "1 0 0\n";
        else{ 
        if(a*x + b*y == d)
            if(a*y + b*x == d && y <= x) 
                cout <<  y << " " << x;
            else
                cout <<  x << " " << y;
        else
            cout <<  y << " " << x;
        cout << " "  << d << "\n";
        }
    }
}