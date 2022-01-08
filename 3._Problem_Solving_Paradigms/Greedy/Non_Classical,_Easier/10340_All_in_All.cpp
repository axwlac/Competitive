#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    while(cin >> s >> t){
        int i = 0, j = 0;
        bool f = false;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                if(i==s.size()-1) {f=true;break;}
                i++;
                j++;
            }
            else j++;
        }
        if(f) cout << "Yes\n";
        else cout << "No\n";
    }
}