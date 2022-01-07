#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

long long MOD;

int mod(long long a, long long b){
    return (((a%b) + b) % b);
}

bool comp_mod(const pair<long long,long long> &x,const pair<long long, long long> &y){
    long long a= x.first%MOD, b= y.first%MOD;
    if(a != b){return a < b;}
    else {
        if(mod(x.first,2)==1 && mod(y.first,2)==0){return true;}
        else if(mod(x.first,2)==0 && mod(y.first,2)==1){return false;}
        else if(mod(x.first,2)==1 && mod(y.first,2)==1){
            return x.first > y.first;
        }
        else if(mod(x.first,2)==0 && mod(y.first,2)==0){
            return x.first < y.first;
        }
    }
}

int main(){
    long long n,m,s;
    while(cin>>n>>m){
        MOD = m;
        if(n!=0 && m!=0){
            vector <pair<long,long>> v;
            while(n--){
             cin>>s;
                v.push_back({s, mod(s,m)});
            }
            sort(v.begin(), v.end(), comp_mod);
            cout << v.size() << " " << m << "\n";
            for(auto x:v){cout << x.first << "\n";}
        }
        else if(n==0 && m==0) {cout << "0 0\n"; break;}
    }
}
