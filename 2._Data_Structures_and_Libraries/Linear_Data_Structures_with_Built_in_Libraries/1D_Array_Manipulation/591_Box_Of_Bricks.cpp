#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,a=0,s=0,i,index=1,np;
    vector <int> j;
    while(cin>>n){
        np = n;
        if(n>0){
            while(n--){
                cin >> i;
                j.push_back(i);
                s = s + i;
            }
            for(int u=0; u < np; u++) {
                if(j[u] < (s/np)) a = a + abs(j[u]-(s/np));
                else continue;
            }
            cout << "Set #" << index << "\n" << "The minimum number of moves is " << a << ".\n\n";
            index++;
            s=0;
            a=0;
            j.clear();
        }
        else break;
    }

    return 0;
}