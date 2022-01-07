#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int,char> &x,const pair<int,char> &y){
    if(x.first!=y.first) return x.first<y.first;
    else return x.second > y.second;
}

int main(){
    string line;
    int index=0;
    while(getline(cin, line)){  
        if(index>0) cout << "\n"; 
        ++index;
        map <int, int> f;
        vector <pair<int,int>> v;
        for(auto a:line){
            if( (32 <= (int)a) && ((int)a <= 128) ){f[(int)a]++;}
        }
        for(auto it:f) v.push_back({(it).second, (it).first});
        sort(v.begin(),v.end(), comp);
        for(auto g:v) cout << g.second << " " << g.first << "\n";
    }
}