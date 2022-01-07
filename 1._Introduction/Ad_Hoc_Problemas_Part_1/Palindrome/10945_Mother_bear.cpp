#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main(){
    string w;
    while( getline(cin,w), w!="DONE"){
        string s="",f;
        for(char t:w){
            if( t=='.'||t==','||t=='!'||t=='?'||t==' '){continue;}
            else{s+=tolower(t);} 
        }
        f=s;
        reverse(f.begin(),f.end());
        if(s==f) cout << "You won't be eaten!\n";
        else cout << "Uh oh..\n";
    }
}