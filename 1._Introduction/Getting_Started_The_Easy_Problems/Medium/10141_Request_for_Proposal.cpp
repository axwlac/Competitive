#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,p,index=1;
    while(cin>>n>>p, (n || p)){
        if(index>1) cout << "\n";
        string s;
        int a,n0,cont=1;
        n0=n;
        double b;
        map <pair<pair<int,double>,int>,string> prop;
        cin.ignore();
        while(n0--){getline(cin,s);}
        while(p--){
            getline(cin,s);
            cin >> b >> a; prop[{{n-a,b},cont++}] = s;
            cin.ignore();
            while(a--){getline(cin,s);}
        }
        cout << "RFP #" << index++ << "\n";
        auto it = prop.begin();
        cout << it->second << "\n";
    }   
}