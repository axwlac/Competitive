#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    string line;
    cin>>n;
    while (n--){
        multimap <int, int> neighbor;
        int index=1;
        cin>>p;
        cin.ignore();
        while (p--){
            int k=0,token;
            getline(cin,line);
            stringstream s(line);
            while (s >> token){k++;}
            neighbor.insert( {k,index++});
        }
        auto f = neighbor.begin();
        int m=(*f).first;
        for(auto it = neighbor.begin(); it!= neighbor.end(); it++){
            if((*it).first==m && it == neighbor.begin()) cout << (*it).second;
            else if((*it).first==m && it != neighbor.begin()) cout << " " <<(*it).second;
            else break;
        }
        cout << "\n";
    }
}   