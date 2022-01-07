#include <iostream>
using namespace std;

int main(){
    int t,n,c,index=1,min=0;
    cin >> t;
    while(t--){
        cin >> n;
        while(n--){
            cin >> c;
            if(c>=min) min = c;
        }
        cout << "Case " << index << ": " << min << "\n";
        index++;
        min=0;
    }
    return 0;
}