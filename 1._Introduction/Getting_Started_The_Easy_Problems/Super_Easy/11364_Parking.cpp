#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int casos, tiendas, posicion;
    vector<int> posvect;
    cin >> casos;
    while(casos--){
        cin >> tiendas;
        while(tiendas--){
            cin >> posicion;
            posvect.push_back(posicion);
        }
    sort(posvect.begin(), posvect.end());
    int a = posvect.size()-1;
    cout << 2*(posvect[a]-posvect[0]) << "\n";
    posvect.clear();
    }
return 0;


}