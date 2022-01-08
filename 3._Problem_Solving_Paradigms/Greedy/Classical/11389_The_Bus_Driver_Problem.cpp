#include <bits/stdc++.h> 
using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d,r;
    while (cin >> n >> d >> r, n!=0, r!=0, d!=0){
        vector <int> morning(n), afternoon(n);
        for(int i =0; i < n; ++i){cin >> morning[i];}
        for(int i =0; i < n; ++i){cin >> afternoon[i];}
        sort(morning.begin(), morning.end());
        sort(afternoon.begin(), afternoon.end());
        int hours=0;
        for(int i=0; i < n; ++i){
            if(morning[i]+afternoon[n-i-1] > d) hours += (morning[i] + afternoon[n-i-1]) - d;
        }
        cout << hours * r << "\n";
    }
    
}