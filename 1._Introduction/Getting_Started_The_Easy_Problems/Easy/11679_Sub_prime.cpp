#include <iostream>
#include <map>
using namespace std;

int main(){
    int b,n;
    while(cin>>b>>n, (b||n)){
        int index=1,d,c,v,hay=0;
        map <int,int> banks;
        while(b--){cin>>c; banks[index++] = c;}
        while(n--){cin>>d>>c>>v;banks[d]-=v;banks[c]+=v;}
        for(auto bank: banks){if(bank.second < 0){hay++;}}
        if(hay>0)cout<<"N\n";
        else cout<<"S\n";
    }
}