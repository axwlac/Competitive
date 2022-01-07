#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    vector <long long> v;
    while(cin>>n){
        v.push_back(n);
        sort(v.begin(), v.end());
        if(v.size()==1){cout << v[0] << "\n";}
        else if(v.size()==2){cout << (v[0]+v[1])/2 << "\n";}
        else if(v.size()%2==1){cout << v[(v.size()/2)] << "\n";}
        else if(v.size()%2==0){cout << (v[(v.size()/2)] +v[(v.size()/2)-1])/2 << "\n";}
    }
}