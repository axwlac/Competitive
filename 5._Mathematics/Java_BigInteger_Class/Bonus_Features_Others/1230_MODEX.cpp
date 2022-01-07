#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long binpow(long long a, long long b, long long m){
    a %= m;
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1; 
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int casos, x, y ,n;
    cin >> casos;
    while(casos--){
        cin >> x >> y >> n;
        cout << binpow(x,y,n) << "\n";
    }
    return 0;
}