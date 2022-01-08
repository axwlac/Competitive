#include <bits/stdc++.h>
using namespace std;


int main(){
    int t, p;
    while (cin>>t){
        vector <int> v(t);
        for(int i=0; i < t; ++i){cin >>  v[i];}
        sort(v.begin(), v.end());
        cin >> p;
        int l = 0, r = t-1; 
        int a,b;
        while (l < r){
            if(v[l]+v[r]<p) l++;
            else if(v[l] + v[r] == p){
                a = l;
                b = r;
                l++; r--;
            }
            else --r;
        }
        cout << "Peter should buy books whose prices are " << v[a] << " and " << v[b] << ".\n\n";
    }   
}