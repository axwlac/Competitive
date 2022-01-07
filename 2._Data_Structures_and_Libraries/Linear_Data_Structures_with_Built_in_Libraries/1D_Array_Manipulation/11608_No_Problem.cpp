#include <iostream> 
#include <vector> 
using namespace std; 

int main(){
    int p,count=1;
    while(cin>>p, p>=0){
        cout << "Case " << count++ << ":\n";
        int s,created[13],required[12];
        created[0] = p;
        for(int i=1; i<13;i++){cin>>s; created[i] = s;}
        for(int i=0; i<12;i++){cin>>s; required[i] = s;}
        p=0;
        for(int i=0; i<12;i++){
            if(p+created[i]>=required[i]){
                cout << "No problem! :D\n";
                p += created[i]-required[i];
            }
            else{
                cout << "No problem. :(\n";
                p += created[i];
            }
        }

    }
}