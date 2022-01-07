#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string h;
    int cont=1;
    while(cin >> h){
        if(h == "HELLO") cout << "Case " << cont << ": " << "ENGLISH\n";
        else if(h == "HOLA") cout << "Case " << cont << ": " << "SPANISH\n";
        else if(h == "HALLO") cout << "Case " << cont << ": " << "GERMAN\n";
        else if(h == "BONJOUR") cout << "Case " << cont << ": " << "FRENCH\n";
        else if(h == "CIAO") cout << "Case " << cont << ": " << "ITALIAN\n";
        else if(h == "ZDRAVSTVUJTE") cout << "Case " << cont << ": " << "RUSSIAN\n";
        else if (h == "#") break;
        else cout << "Case " << cont << ": " << "UNKNOWN\n";
        cont++;
    }
    return 0;
}