#include <iostream>
#include <vector>
using namespace std;


int main(){
    int l;
    while(cin >> l , l!=0){
        string s;
        int z=0,mini=0;
        vector <int> resto, drugs;
        cin >> s;
        for(int i=0;i<l;i++){
            if(s[i]=='R') resto.push_back(i+1);
            else if(s[i]=='D') drugs.push_back(i+1);
            else if(s[i]=='Z'){z++; break;}
        }
        if(z!=0) cout << 0 << "\n";
        else if(z==0){
            for(int i=0;i<resto.size();i++){
                for(int k=0;k<drugs.size();k++){
                    if(mini==0) mini+= abs(drugs[k]-resto[i]);
                    else{
                        if(mini < abs(drugs[k]-resto[i])) continue;
                        else if(mini >= abs(drugs[k]-resto[i])) mini = abs(drugs[k]-resto[i]);
                    }
                }
            }
            cout << mini << "\n";
        }
    }

}