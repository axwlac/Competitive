#include <bits/stdc++.h> 
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double n , k;
    while (cin >> n >> k){
        long double digits = 0;
        for(int i=0; i <= k-1; ++i){digits += log10((long double)(n-i)) - log10((long double)(i+1));}
        long long total = (long long) digits + 1;
        cout << total << "\n";
    }
}