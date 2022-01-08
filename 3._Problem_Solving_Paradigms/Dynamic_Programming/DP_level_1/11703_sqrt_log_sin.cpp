#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

int memo[1000005];

int dp(int i){
    if(i==0) return 1;
    int &ans = memo[i];
    if(ans != -1) return ans;
    double k = (double)i;
    int f = (int)floor(k - sqrt(k));
    int s = (int)log(k);
    int t = (int)(k * sin(k) * sin(k));
    // cout << "pos: " << f << ", " << s << ", " << t << ".\n";
    return ans =  (dp(f) + dp(s) + dp(t))% 1000000;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(memo, -1, sizeof memo);
    int n;
    while(cin >> n, n!=-1){
        cout << dp(n) << "\n";
    }
}