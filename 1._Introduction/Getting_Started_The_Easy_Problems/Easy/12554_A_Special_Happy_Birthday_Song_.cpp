#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    string s;
    vector <string> v;
    vector <string> h1={"Happy", "birthday", "to", "you","Happy", "birthday", "to", "you","Happy", "birthday", "to", "Rujia","Happy", "birthday", "to", "you"};
    cin >> n;
    while(n--){cin >> s; v.push_back(s);}
    if(v.size()<=h1.size()){
        for(int i=0;i<h1.size();i++){
            if(i<v.size()){cout << v[i] << ": " << h1[i] << "\n";}
            else if(i>=v.size()){cout << v[i-(v.size()*(i/v.size()))] << ": " << h1[i] << "\n";}
        }
    }
    else{
        int a=h1.size()*((v.size()/h1.size())+1);
        for(int i=0;i<a;i++){
            if(i<h1.size()){cout << v[i] << ": " << h1[i] << "\n";}
            else if(i>=h1.size() && i<v.size()){cout << v[i] << ": " << h1[i-(h1.size()*(i/h1.size()))] << "\n";}
            else {cout << v[i-(v.size()*(i/v.size()))] << ": " << h1[i-(h1.size()*(i/h1.size()))] << "\n";}
        }
    }
}