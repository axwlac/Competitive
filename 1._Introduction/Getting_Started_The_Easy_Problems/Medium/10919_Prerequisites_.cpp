#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int k,m;
    while(cin>>k>>m, k!=0){
        int ki,r,c,i=0;
        vector <int> v;
        while(k--){cin>>ki; v.push_back(ki);}
        sort(v.begin(),v.end());
        while(m--){
            int d=0;
            cin>>c>>r;
            while(c--){
                cin>>ki;
                if( binary_search(v.begin(),v.end(),ki) ){d++;}
            }
            if(d<r) i++;
        }
        if(i>0) cout << "no\n";
        else  cout << "yes\n";
    }
    return 0;
}