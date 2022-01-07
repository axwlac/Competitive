#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    int n,months;
    double loan,down;
    while(cin>>n>>down>>loan>>months, n>0){
        int s,N=n;
        vector <int> v;
        map <int,double> x;
        double f,original_loan=loan, car_val=loan+down,depreciation=0;
        while(months--){
            cin>>s>>f;
            v.push_back(s);
            x[s] = f;
        }
        while(n--){
            if(N-n-1>0) loan -= original_loan/N;
            for(int i=0;i<v.size()-1;i++){
                if(v[i]<=N-n-1 && N-n-1<v[i+1]) {depreciation = x[v[i]];}
                else if(N-n-1>=v[v.size()-1]) {depreciation = x[v[v.size()-1]];}
            }
            car_val -= car_val * depreciation;
            if(car_val>loan) break;
        }
        if(N-n>2 || N-n-1==0)cout << N-n-1 << " months\n";
        else if(N-n-1==1) cout << "1 month\n";
    }
}