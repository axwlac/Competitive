#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t;
    while(cin >> t, t!=0){
        queue <int> q;
        vector <int> v;
        for(int i=1; i<=t; ++i){q.push(i);}
        if(t>1){
        while(q.size()>2){
            v.push_back(q.front());
            q.pop();
            int x=q.front();
            q.push(x);
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
        cout << "Discarded cards: " ;  
        for(int i=0; i<v.size(); i++){
            if(i==v.size()-1) cout << v[i];
            else cout << v[i] << ", ";
        }
        cout << "\n";
        cout << "Remaining card: " << q.front() << "\n";
        }
        else{
            cout << "Discarded cards:\n" ; 
            cout << "Remaining card: 1\n";
        }
    }
}