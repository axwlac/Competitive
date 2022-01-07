#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int t;
    string line, token;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin,line);
        stringstream s(line);
        int mf=0,mm=0,ff=0;
        while(s >> token){
            //cout << token << "\n";
            if(token=="MF" || token=="FM") mf++;
            else if(token=="FF") ff++;
            else if(token=="MM") mm++;
        }
        //cout << (int)(mf>1) << "\n";
        if(mf>1 && mm==0 && ff==0) cout << "LOOP\n";
        else if(mf==1 && mm==0 && mf==0) cout << "NO LOOP\n";
        else if(mm>=1 && mm==ff) cout << "LOOP\n";
        else cout << "NO LOOP\n";
    }
}