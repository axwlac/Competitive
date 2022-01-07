#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

struct person{
    string name;
    int dd;
    int mm;
    int yyyy;
};

bool age_comp(const person &x, const person &y){
    if(x.yyyy != y.yyyy) return x.yyyy < y.yyyy;
    else if(x.mm != y.mm) return x.mm < y.mm;
    else if(x.dd != y.dd) return x.dd < y.dd;
}


int main(){
    int t,day,month,year,t0; string line,n;
    cin>>t; cin.ignore(); t0=t;
    vector <person> people;
    while(t--){
        getline(cin, line);
        stringstream s(line);
        s>>n>>day>>month>>year;
        person p;
        p.name=n; p.dd=day; p.mm=month; p.yyyy=year;
        people.push_back(p);
    }
    sort(people.begin(), people.end(), age_comp);
    if(t0==1){cout << people[0].name << "\n";}
    else {cout << people[people.size()-1].name << "\n" << people[0].name << "\n";}
}