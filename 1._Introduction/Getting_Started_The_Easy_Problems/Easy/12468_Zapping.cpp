#include <iostream>
using namespace std;

int main(){
    int a,b;
    while(cin >> a >> b){
        if(a==-1 && b==-1) break;
        else if(b <= a){
            if(abs(a-b) <= abs((b+100)-a)) cout << abs(a-b) << "\n";
            else cout << abs((b+100)-a) <<"\n";
        }
        else {
            if(abs(b-a) <= abs((a+100)-b)) cout << abs(b-a) << "\n";
            else cout << abs((a+100)-b) <<"\n";
        }
    }
    return 0;
}