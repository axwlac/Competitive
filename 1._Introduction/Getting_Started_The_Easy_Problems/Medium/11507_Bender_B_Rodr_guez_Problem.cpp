#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

 int main(){
    int t;
    map <pair<string,string>,string> op;
    op[{"+x","+x"}] = "+x";op[{"+x","+y"}] = "+y";op[{"+x","+z"}] = "+z";op[{"+x","-x"}] = "-x";op[{"+x","-y"}] = "-y";op[{"+x","-z"}] = "-z";
    op[{"+y","+x"}] = "+y";op[{"+y","+y"}] = "-x";op[{"+y","+z"}] = "+y";op[{"+y","-x"}] = "-y";op[{"+y","-y"}] = "+x";op[{"+y","-z"}] = "+y";
    op[{"+z","+x"}] = "+z";op[{"+z","+y"}] = "+z";op[{"+z","+z"}] = "-x";op[{"+z","-x"}] = "-z";op[{"+z","-y"}] = "+z";op[{"+z","-z"}] = "+x";
    op[{"-x","+x"}] = "-x";op[{"-x","+y"}] = "-y";op[{"-x","+z"}] = "-z";op[{"-x","-x"}] = "+x";op[{"-x","-y"}] = "+y";op[{"-x","-z"}] = "+z";
    op[{"-y","+x"}] = "-y";op[{"-y","+y"}] = "+x";op[{"-y","+z"}] = "-y";op[{"-y","-x"}] = "+y";op[{"-y","-y"}] = "-x";op[{"-y","-z"}] = "-y";
    op[{"-z","+x"}] = "-z";op[{"-z","+y"}] = "-z";op[{"-z","+z"}] = "+x";op[{"-z","-x"}] = "+z";op[{"-z","-y"}] = "-z";op[{"-z","-z"}] = "-x";
     while(cin>>t, t!=0){
         vector <string> v;
        string s,initial="+x"; t--;
        while(t--){
            cin>>s;
            if(s=="No") continue;
            else v.push_back(s);
        }
        for(int i=0;i<v.size();i++){
            initial = op[{initial,v[i]}];    
        }
        cout << initial << "\n";
     }
 }