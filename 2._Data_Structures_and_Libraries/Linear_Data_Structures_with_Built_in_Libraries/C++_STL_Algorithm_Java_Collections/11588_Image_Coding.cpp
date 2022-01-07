#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int x, r,c,m,n, i=1;
    char k;
    cin>>x;
    while (x--){
        map <char, int> f;
        cin>>r>>c>>m>>n;
        int u=r*c, max=0, val=0;
        while (u--){
            cin>>k;
            f[k]++;
        }
        for(auto it: f){if(it.second>max) max = it.second;}
        for(auto it: f){
            if(it.second==max) val+= (m*(it.second)); //cout << it.first << " : " << it.second << "\n";}
            else val+= (n*(it.second)); //cout << it.first << " : " << it.second << "\n";}
        }
        cout << "Case " << i++ << ": " << val << "\n";
    }
}