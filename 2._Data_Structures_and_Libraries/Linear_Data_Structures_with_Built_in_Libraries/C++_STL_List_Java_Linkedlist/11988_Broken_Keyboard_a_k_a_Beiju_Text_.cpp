#include <iostream>
#include <list>
using namespace std;

int main(){
    string s;
    list <char> mylist;
    while (cin>>s){
        auto it = mylist.begin();
        for(char c: s){
            if(c=='['){it = mylist.begin();}
            else if(c==']'){it = mylist.end();}
            else{mylist.insert(it,c);}
        }
        for(auto it = mylist.begin(); it!=mylist.end(); ++it){cout << *it;}
        cout << "\n";
        mylist.clear();
    }
}