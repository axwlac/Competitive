#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

string rec(string h){
    while(h.size()>1){
        int a=0;
        for(int i=0; i<h.size(); i++) a += (int) h[i] - 48;
        h = to_string(a);
    }
    return h;
}

int main(){
    string s1;
    while(getline(cin,s1)){
        string s2,h1,h2;
        int sum1=0, sum2=0,a,b;
        getline(cin,s2);
        for(int i=0;i < s1.size();i++){
            if(65 <= (int)s1[i] && (int)s1[i] <= 90) sum1+= ((int)s1[i]) - 64;
            else if(97 <= (int)s1[i] && (int)s1[i] <= 122) sum1+= ((int)s1[i]) - 96;
            else continue;
        }
        for(int i=0;i < s2.size();i++){
            if(65 <= (int)s2[i] && (int)s2[i] <= 90) sum2+= ((int)s2[i]) - 64;
            else if(97 <= (int)s2[i] && (int)s2[i] <= 122) sum2+= ((int)s2[i]) - 96;
            else continue;
        }
        h1 = to_string(sum1);
        h2 = to_string(sum2);
        a= (int) rec(h1)[0] -48;
        b= (int) rec(h2)[0] -48;
        cout << fixed << setprecision(2)<< ((double)(min(a,b))/( (double) max(a, b) ))*100 << " %\n";
    }
}