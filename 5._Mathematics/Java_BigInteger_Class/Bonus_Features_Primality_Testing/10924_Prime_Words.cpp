#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main(){
    string s;
    while(cin>>s){
        int value=0;
        for(char x:s){
            if((int)x>=97 && (int)x<=122 ){value += (int)x-96;}
            else if((int)x>=65 && (int)x<=90 ){value += (int)x-38;}
        }
        if(isPrime(value)) cout << "It is a prime word.\n";
        else cout << "It is not a prime word.\n";
    }
}