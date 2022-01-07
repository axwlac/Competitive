#include <iostream>
#include <cmath>
using namespace std;

long long reverse(long long num){
    long long digit, rev=0;
    do{
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);
    return rev;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a,r=0,index=1,aux; 
        cin>>a;
        r= reverse(a);
        do{
            if( a+r==reverse(a+r) ) break;
            else{
                aux=reverse(a+r);
                a=a+r;
                r=aux;
                index++;
            }
        } while(a!=r);
        cout << index << " " << r+a << "\n";
    }
}