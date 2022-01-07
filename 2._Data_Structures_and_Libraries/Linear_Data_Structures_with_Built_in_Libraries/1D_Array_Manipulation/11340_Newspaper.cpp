#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(){
    int t,pl,l;
    double p;
    char c;
    cin>>t;
    while(t--){
        double pay=0.00;
        string line;
        map <char,double> f;
        cin>>pl;
        while(pl--){cin>>c>>p; f[c] = p/100;}
        cin>>l;
        l++;
        while(l--){
            getline(cin,line);
            for(char i:line){pay+=f[i];}
            // cout << line<< "\n";
        }
        cout <<fixed<< setprecision(2) <<pay << "$\n";
    }
}