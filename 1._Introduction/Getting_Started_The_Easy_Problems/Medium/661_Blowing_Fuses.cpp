#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,c,index=1;
    while(cin>>n>>m>>c, n!=0, m!=0, c!=0){
        cout << "Sequence " << index << "\n";
        vector <int> v; v.push_back(0);
        vector <bool> b; b.push_back(0);
        int ci,s=0;
        while(n--){cin>>ci; v.push_back(ci); b.push_back(0);}
        while(m--){
            int k=0;
            cin>>ci;
            b[ci] = !b[ci];
            for(int i=0;i<v.size(); i++){k += v[i] * (int)b[i]; if(s<=k) s=k;}
            }
        if(s<=c){cout << "Fuse was not blown.\n"<< "Maximal power consumption was " << s <<" amperes.\n\n";}
        else cout << "Fuse was blown.\n\n";
        index++;
    }
    return 0;
}