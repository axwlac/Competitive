#include <iostream>
#include<algorithm>
using namespace std;
int sumdig(int h){
    int g;
    if(h%10==h)return h;
    else{
        g=h%10;
        h-g; h/=10;
        h+=g;
        return h;
    } 
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        int doub=0,nodoub=0;
        string s;
        getline(cin,s);
        s.erase(remove(s.begin(),s.end(),' ') );
        for(int d=0;d<s.length()-2;d++){
            if(d%2==0){doub+=sumdig( 2*((int)s[d]-48) );}
            else {nodoub+= ((int)s[d])-48;}
        }
        if((doub+nodoub)%10==0) cout << "Valid\n";
        else cout << "Invalid\n";
    }
}
//5181 2710 9900 0017