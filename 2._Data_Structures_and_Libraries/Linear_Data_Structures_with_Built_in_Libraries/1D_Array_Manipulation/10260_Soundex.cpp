#include <iostream>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        string f="",g="";
        for(char h:s){
            if(h=='B'||h=='F'||h=='P'||h=='V'){f+='1';}
            else if(h=='C'||h=='G'||h=='J'||h=='K'||h=='Q'||h=='S'||h=='X'||h=='Z'){f+='2';}
            else if(h=='D'||h=='T'){f+='3';}
            else if(h=='L'){f+='4';}
            else if(h=='M'||h=='N'){f+='5';}
            else if(h=='R'){f+='6';}
            else{f+='0';}
        }
        f+='0';
        for(int h=0;h<f.length()-1;h++){
            if(f[h]!=f[h+1] && f[h]!='0'){g+=f[h];}
        }
        cout << g << "\n";
    }
}