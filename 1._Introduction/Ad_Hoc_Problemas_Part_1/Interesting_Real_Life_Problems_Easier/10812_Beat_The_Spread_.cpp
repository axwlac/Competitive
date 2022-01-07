#include <iostream>
using namespace std;

int main(){
    int t,s,d;
    cin >> t;
    while(t--){
        cin >> s >> d;
        if(s < d) cout << "impossible\n";
        else if(s%2==0 && d%2==1) cout << "impossible\n";
        else if(s%2==1 && d%2==0) cout << "impossible\n";
        else cout << s-((s-d)/2) << " " << (s-d)/2 << "\n";
    }
    return 0;
}