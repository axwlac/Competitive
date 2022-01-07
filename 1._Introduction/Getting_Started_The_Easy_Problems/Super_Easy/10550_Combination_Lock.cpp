#include <iostream>
using namespace std;

int main(){
    int i,f,s,t;
    while(cin>>i>>f>>s>>t, (i||f||s||t)){
        int d=1080;
        if(f<=i){
            d+=9*(i-f);
            if(s>=f){
                d+= 9*(s-f);
                if(t<=s) d+= 9*(s-t);
                else d+= 9*(s+40-t);
            }
            else {
                d+= 9*(s+40-f);
                if(t<=s) d+= 9*(s-t);
                else d+= 9*(s+40-t);
            }
        }
        else {
            d+=9*(i+40-f);
            if(s>=f){
                d+= 9*(s-f);
                if(t<=s) d+= 9*(s-t);
                else d+= 9*(s+40-t);
            }
            else {
                d+= 9*(s+40-f);
                if(t<=s) d+= 9*(s-t);
                else d+= 9*(s+40-t);
            }
        }
        cout << d << "\n";
    }
}