#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin>>n, n!=0){
        int m=n;
        cin.ignore();
        string line;
        int blank=0, min=25;
        while(n--){
            int perline=0;
            getline(cin, line);
            for(char b: line){if(b==' '){perline ++;}}
            if(perline<min) min=perline;
            blank += perline;
        }
        cout << blank-(m*min) << "\n";
    }
}