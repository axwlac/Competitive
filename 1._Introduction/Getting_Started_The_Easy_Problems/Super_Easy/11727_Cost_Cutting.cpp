#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int casos, conta, pers1, pers2, pers3;
    vector<int> persvec;
    cin >> casos;
    conta = 0;
    while (casos--){
        conta++;
        cin >>  pers1 >> pers2 >> pers3;
        persvec.push_back(pers1);
        persvec.push_back(pers2);
        persvec.push_back(pers3);
        sort(persvec.begin(), persvec.end());
        cout << "Case " << conta << ": " << persvec[1] << "\n";
        
        persvec.clear();
    }
    
    return 0;
}