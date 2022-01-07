#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

bool str_com(const string &s, const string &t){
    if(s+t != t+s) return s+t < t+s;
    else return s+t > t+s;
}

int main(){
    int n; 
    while(cin>>n, n!=0){
        string num = "", s;
        vector <string> v;
        while (n--){
            cin>>s; v.push_back(s);
        }
        sort(v.rbegin(), v.rend(), str_com);
        for(auto w:v){num += w;}
        // for(int w=v.size()-1; 0<w; --w){num += v[w];}
        cout << num << "\n";
        // cout << (bool)("990" < "909") << "\n";
    }
}