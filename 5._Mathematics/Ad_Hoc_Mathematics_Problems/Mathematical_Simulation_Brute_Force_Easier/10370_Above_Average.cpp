#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int c; 
    cin >> c;
    while(c--){
        vector <int> v;
        int students,calif;
        double average=0,res,n,count=0.0;
        cin>>students;
        n=(double)students;
        while(students--){cin>>calif; average+=calif; v.push_back(calif);}
        average /= n;
        for(int i:v){if(i>average) count = count+1;}
        res=(double)( (count*100)/n);
        cout << fixed << setprecision(3) << res << "%\n";
    }
}