#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,d;
ll maxi = 1e-9;
ll year[12];

void bt(int it){
    
    if(it == 12){
        bool can = true;
        for(int i = 0; i < 8; ++i){
            ll sum = 0;
            for(int k =i ; k < i+5; ++k){
                sum += year[k];
            }
            if(sum > 0) can = false;
        }
        if(can){
            ll total=0;
            for(auto k: year) total += k;
            maxi =  max(total, maxi);
        }
        return;
    }

    year[it] = s;
    bt(it + 1); 
    year[it] = d;
    bt(it + 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> s >> d){
        d *= -1;
        memset(year, 0, sizeof year);
        bt(0);
        if(maxi > 0) cout << maxi << "\n";
        else cout << "Deficit\n";
        maxi = 1e-9;
    }
}