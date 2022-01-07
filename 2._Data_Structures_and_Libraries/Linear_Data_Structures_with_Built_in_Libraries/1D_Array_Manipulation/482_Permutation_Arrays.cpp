#include <iostream> 
#include <vector>
#include <sstream>
#include <string> 
using namespace std; 

int main(){
    int t, index=0;
    string s,c,blank;
    cin >> t;
    cin.ignore();
    while(t--){
        if(index++>0) cout << "\n";
        vector <int> k;
        int maximum=0;
        string token;
        int tok;
        getline(cin,blank);
        getline(cin,s);
        getline(cin,c);
        stringstream f(s);
        while(f >> tok){k.push_back(tok); if(tok>maximum) maximum = tok;}
        // cout << "maximum: " << maximum<< "\n"; 
        // for(int y:k){cout << y << "\n";}
        vector <string> v, j(maximum, " ");
        stringstream d(c);
        while(d >> token){v.push_back(token); /*cout << token << "\n";*/}
        for(int i=0;i<maximum; i++){j[k[i]-1] = v[i];}
        for(string r:j){cout << r << "\n";}
    }
}