#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t,n;
    string s;
    cin >> t;
    while(t--){
        int pos=0;
        vector <string> v;
        v.push_back(" ");
        cin >> n;
        cin.ignore();
        while(n--){
            getline(cin,s);
            v.push_back(s);
            if(s=="LEFT") pos -= 1;
            else if(s=="RIGHT") pos += 1;
            else{
                if(s[s.size()-2] ==' '){
                    int a= (int) s[s.size()-1] - 48;
                    if(v[a] == "LEFT"){
                    pos -= 1;
                    v[v.size()-1] = "LEFT";
                    }
                    if(v[a] == "RIGHT"){
                    pos += 1;
                    v[v.size()-1] = "RIGHT";
                    }
                }
                else if(s[s.size()-2] !=' '){
                    int a= (int)s[s.size()-1] - 48;
                    int b= ((int)s[s.size()-2] - 48)*10;
                    if(v[a+b] == "LEFT"){
                    pos -= 1;
                    v[v.size()-1] = "LEFT";
                    }
                    if(v[a+b] == "RIGHT"){
                    pos += 1;
                    v[v.size()-1] = "RIGHT";
                    }      
                }
            }
        }
        cout << pos << "\n";
    }
}