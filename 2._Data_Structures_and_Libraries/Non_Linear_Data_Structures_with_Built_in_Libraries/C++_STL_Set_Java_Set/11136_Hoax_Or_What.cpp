#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,k,bill;
    while (cin>>n , n!=0){
        multiset <int> A; long long total=0;
        while (n--){
            cin>>k;
            while (k--){cin>>bill; A.insert(bill);}
            auto it1=A.begin(); auto it2=A.end(); --it2;
            total+= (*it2)-(*it1);
            A.erase(it1); A.erase(it2);
        }
        cout << total << "\n";
    }
}