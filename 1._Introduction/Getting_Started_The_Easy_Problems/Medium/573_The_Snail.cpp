#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double H,U,D,F;
    while(cin >> H >> U >> D >> F, H!=0){
        int day=0;
        double  initial=0;
        F = (U*F)/100.0;
        while(1){
            day++;
            initial += U;
            U-=F;
            if(U<0) U=0;
            if(initial>H) break;
            initial -= D;
            if(initial<0) break;
        }
        if(initial>=H) cout << "success on day " << day << "\n";
        else if(initial<0) cout << "failure on day " << day << "\n";
    }
    return 0;
}
