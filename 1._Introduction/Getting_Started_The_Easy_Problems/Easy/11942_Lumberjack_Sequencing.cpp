#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t,a;
    char s;
    cout << "Lumberjacks:\n";
    cin >> t;
    while(t--){
        int j=10;
        vector <int> v,d,x;
        while(j--){
            cin >> a;
            v.push_back(a);
        }
        d = v;
        x = v;
        sort(d.begin(),d.end());
        sort(x.rbegin(),x.rend());
        if(v==d || v==x) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}