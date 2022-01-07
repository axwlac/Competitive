#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t, index=1;
    cin >> t;
    while(t--){
        int N,a,si=0,ss=0;
        vector <int> v;
        cin >> N;
        while(N--){
            cin >> a;
            v.push_back(a);
        }
        for(int i=0; i<v.size()-1;i++){
            if(v[i]<v[i+1]) ss++;
            else if(v[i]>v[i+1]) si++;
        }
        cout << "Case " << index << ": " << ss << " " << si << "\n";
        index++;
    }
}