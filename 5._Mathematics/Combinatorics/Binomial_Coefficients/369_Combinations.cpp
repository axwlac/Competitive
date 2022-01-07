#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;


double combinaciones(double l, double k){
    if(l < 0 || k < 0) return 0;
    else if(l > 0 &&  k > 0 && l > k) return (l/k)*combinaciones(l-1,k-1);
    else if (k = 0) return 1;
    else return 1;
    }

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
    double n, m, x;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        x = combinaciones(n,m);
        cout << fixed << setprecision(0) << n << " things taken "<< m << " at a time is " << x << " exactly."<< "\n";
        
    }
    return 0;
}