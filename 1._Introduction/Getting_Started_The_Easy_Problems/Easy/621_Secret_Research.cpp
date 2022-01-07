#include <iostream>
using namespace std;

int main(){
    string s;
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        if(s=="1" || s=="4"|| s=="78") cout << "+\n";
        if(s.size()>2){
        if(s[s.size()-1]=='5' && s[s.size()-2]=='3') cout << "-\n";
        else if(s[0]=='9' && s[s.size()-1]=='4') cout << "*\n";
        else cout << "?\n";
        }
    }
    return 0;
}