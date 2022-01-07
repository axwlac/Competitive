#include <iostream>
#include <vector>
using namespace std;

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
    long long int k;
    while(cin>>k, k!=0){
        if(k==1) cout<<"1 = \n";
        else if(k==-1) cout<<"-1 = -1 x \n";
        else{
        vector <long long> v;
        if(k>0) {v = trial_division1(k); cout << k << " =";}
        else if(k<0) {v = trial_division1(-k); cout << k << " = -1 x";}
        for(long long j=0;j<v.size();j++){
            if( j==v.size()-1 ) {cout<< " "<< v[j];} 
            else cout << " "<< v[j] << " x";
            }
        cout << "\n";
        }
    }
}