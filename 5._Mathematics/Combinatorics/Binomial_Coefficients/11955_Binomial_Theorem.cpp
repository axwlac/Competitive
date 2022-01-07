#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double combinaciones(double l, double k){
    if(l < 0 || k < 0) return 0;
    else if(l > 0 &&  k > 0 && l > k) return (l/k)*combinaciones(l-1,k-1);
    else if (k = 0) return 1;
    else return 1;
    }

int main(){
    int t,index=1;
    cin>>t;
    while(t--){
        int n,pos1, pos2;
        string s,s1,s2,nk;
        cin>>s;
        pos1=s.find("+"); pos2=s.find(")");
        s1=s.substr(1,pos1-1);
        s2=s.substr(pos1+1,pos2-pos1-1);
        nk=s.substr(pos2+2,s.size()-1);
        if(nk.size()==1){n=(int)nk[0] - 48;}
        else if(nk.size()==2){n= ((int)nk[0] - 48 )*10 + ((int)nk[1] - 48 );}
        cout << "Case " << index++ << ": ";
        if(n==1){cout << s1 <<"+"<<s2<< "\n";}
        else{
        for(int i=0;i<=n;i++){
            if(i==0){cout << s1 << "^"<< n-i<<"+";}
            else if(i==n){cout << s2 << "^"<<n<<"\n";}
            else if(n-i==1 && i==1){cout <<fixed << setprecision(0)<< combinaciones((double)n,(double)i) << "*"<<s1<<"*"<<s2<<"+";}
            else if(i==1){cout <<fixed << setprecision(0) <<combinaciones((double)n,(double)i) << "*"<<s1<<"^"<<n-i<<"*"<<s2<<"+";}
            else if(n-i==1){cout <<fixed << setprecision(0) <<combinaciones((double)n,(double)i) << "*"<<s1<<"*"<<s2<<"^"<<i<<"+";}
            else {cout <<fixed << setprecision(0) <<combinaciones((double)n,(double)i) << "*"<<s1<<"^"<<n-i<<"*"<<s2<<"^"<<i<<"+";}
        }
        }
    }
}