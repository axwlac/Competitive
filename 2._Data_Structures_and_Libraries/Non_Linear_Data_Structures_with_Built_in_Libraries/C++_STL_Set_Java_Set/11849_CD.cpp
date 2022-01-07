#include <iostream>
#include <set>
using namespace std;

int main(){
    long int n,m,s;
    while(cin>>n>>m, (n || m)){
        set <long int> X;
        long int i=0;
        while(n--){
            cin>>s;
            X.insert(s);
        }
        while(m--){
            cin>>s;
            if(X.count(s)==1) i++;
        }
        cout << i << "\n";
    }
}