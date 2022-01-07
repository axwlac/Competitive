#include <iostream>
using namespace std;

int main(){
    int t,n,k,p,i=1;
    cin >> t;
    while(t--){
        cin >> n >> k >> p;
        if((k+p)%n==0) cout << "Case " << i << ": " << n << "\n";
        else cout << "Case " << i << ": " << (k+p)%n << "\n";
        i++;
    }
    return 0;
}