#include <iostream>
using namespace std;

int main(){
    long int a,b,d,c,L;
    while(cin>>a>>b>>c>>d>>L,(a||b||c||d||L)){
        long int i=0;
        for(long int x=0;x<=L;x++){
            if(((a*x*x)+(b*x)+c)%d==0) i++;
            // cout << (a*x*x)+(b*x)+c << " ";
            }
        cout << i << "\n";
    }
}