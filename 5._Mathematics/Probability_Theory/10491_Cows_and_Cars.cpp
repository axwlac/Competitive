#include <bits/stdc++.h> 
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    double NCOWS, NCARS, NSHOW;
    while (cin >> NCOWS >> NCARS >> NSHOW){
        double PriorCOW = (NCOWS/(NCOWS+NCARS));
        double S_CAR0 = (NCARS/(NCARS+NCOWS-NSHOW-1));

        double PRIORCAR = (NCARS/(NCOWS+NCARS));
        double S_CAR1 = ((NCARS-1)/(NCARS+NCOWS-NSHOW-1));

        cout << fixed << setprecision(5) << (PriorCOW*S_CAR0) + (PRIORCAR*S_CAR1) << "\n";
    }
}