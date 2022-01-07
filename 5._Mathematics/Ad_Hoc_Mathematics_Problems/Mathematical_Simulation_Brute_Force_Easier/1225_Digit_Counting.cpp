#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s = "";
        short uno=0,dos=0,tres=0,cuatro=0,cinco=0,seis=0,siete=0,ocho=0,nueve=0,cero=0;
        short n; cin>>n;
        for(short i=1; i<=n; i++){s += to_string(i);}
        for(char a:s){
            if(a=='0'){cero++;}
            else if(a=='1'){uno++;}
            else if(a=='2'){dos++;}
            else if(a=='3'){tres++;}
            else if(a=='4'){cuatro++;}
            else if(a=='5'){cinco++;}
            else if(a=='6'){seis++;}
            else if(a=='7'){siete++;}
            else if(a=='8'){ocho++;}
            else if(a=='9'){nueve++;}
        }
        cout << cero<< " " <<uno << " " << dos << " " << tres<< " " << cuatro<< " " <<cinco<< " " <<seis<< " " <<siete<< " " <<ocho<< " " <<nueve<<"\n";
    }
}