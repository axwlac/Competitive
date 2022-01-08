#include <bits/stdc++.h>
using namespace std;
int coinValue[5] = {50, 25 ,10 ,5 , 1};
int memo[5][7500];

int dp(int type, int value){
    if(value==0) return 1;
    if((value < 0) || (type == 5)) return 0;
    int &ans = memo[type][value];
    if(ans != -1) return ans;
    return ans = dp(type+1, value) + dp(type, value-coinValue[type]);
}

int main(){
    int n;
    memset(memo, -1, sizeof memo);
    while (cin>>n){
        cout << dp(0, n) << "\n";        
    }   
}