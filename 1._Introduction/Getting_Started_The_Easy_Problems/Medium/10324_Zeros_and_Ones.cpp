#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    string s;
    int index=1;
    while(cin >> s){
        int n;
        cin >> n;
        cout << "Case " << index << ":\n";
        while(n--){
            int i,j,sum=0;
            cin >> i >> j;
            for(int l=min(i,j);l<=max(i,j);l++){
                sum += (int) s[l];
            }
            if(48*(max(i,j)-min(i,j)+1)==sum || 49*(max(i,j)-min(i,j)+1)==sum){cout << "Yes\n";}
            else {cout << "No\n";}
        }
        index++;
    }   
}