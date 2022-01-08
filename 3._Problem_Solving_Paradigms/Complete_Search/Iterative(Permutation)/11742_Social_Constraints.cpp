#include <bits/stdc++.h>
using namespace std;

struct people
{
    int a;
    int b;
    int c;
};


int main(){
    int n,m; 
    while (cin >> n>> m,(m||n)){
        vector <people> G;
        while (m--){
            people couple;
            cin>> couple.a >> couple.b >> couple.c ;
            G.push_back(couple);
        }
        int index=0;
        vector <int> p(n);
        for(int i = 0; i <n; ++i){p[i] = i;}
        do{
            bool flag = true;
            for(auto x: G){
                int l,r;
                for(int k=0; k<n; ++k){
                    if(p[k]==x.a) l=k;
                    else if(p[k]==x.b) r=k;
                }
                if(x.c>0){
                    if(abs(l-r)>abs(x.c)) {
                        flag = false; 
                        break;
                    }
                }
                else if(x.c<0){
                    if(abs(l-r)<abs(x.c)){
                        flag = false;
                        break;
                    }
                }

            }
            if(flag) index++;
        }while(next_permutation(p.begin(),p.end()));
        cout << index << "\n";
    } 
}