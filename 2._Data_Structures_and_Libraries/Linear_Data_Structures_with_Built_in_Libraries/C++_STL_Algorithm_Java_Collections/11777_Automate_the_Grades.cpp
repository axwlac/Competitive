#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    int t,t1,t2,f,a,c1,c2,c3,n=1;
    cin>>t;
    while (t--){
        vector <int> v;
        int grade=0;
        cin>>t1>>t2>>f>>a>>c1>>c2>>c3;
        grade+=t1; grade+=t2; grade+=f; grade+=a;
        v.push_back(c1); v.push_back(c2); v.push_back(c3);
        sort(v.rbegin(),v.rend());
        grade+=(v[0]+v[1])/2;
        cout << "Case " << n++ << ": ";
        if(grade < 60) cout <<"F\n";
        else if(grade < 70) cout << "D\n";
        else if(grade < 80) cout << "C\n";
        else if(grade < 90) cout << "B\n";
        else if(grade >= 90) cout << "A\n";
    }
}

