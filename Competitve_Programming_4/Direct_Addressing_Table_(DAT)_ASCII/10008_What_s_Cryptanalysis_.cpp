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
    int n; cin>>n; cin.ignore();
    string line;
    vector <pair<int,char>> v;
    map <char, int> letters;
    letters['1']=0;
    while(n--){
        getline(cin,line);
        for(auto x:line){
            if(65 <= (int)toupper(x) && toupper(x) <= 90){letters[toupper(x)]++;}
        }
    }
    auto it = letters.end(); it--;
    for( ;it!=letters.begin();--it){v.push_back({(*it).second,(*it).first});}
    sort(v.rbegin(),v.rend(), comp);
    for(auto y:v){cout << y.second << " " << y.first << "\n";}
}