#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    int t,l; cin >> t;
    while(t--){
        long long sum=0, index=1;
        vector <int> v;
        while (cin>>l, l!=0) v.push_back(l);
        sort(v.rbegin(),v.rend());
        for(int i:v){sum += 2*(binpow(i,index++));}
        if(sum>=5000000 || sum<0) cout << "Too expensive\n";
        else cout << sum << "\n";
    }
}