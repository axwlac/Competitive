#include <iostream>
using namespace std;

int main(){
    int t,index=1;
    cin>>t;
    while(t--){
        int a,b,s=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++) if(i%2 !=0) s+=i;
        cout << "Case "<< index <<": "<< s <<"\n";
        index++;
    }
}