#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    int token;
    vector <int> v, v0;
    map<int,int> number;
    while(getline(cin, line)){
        stringstream s(line);
        while(s >> token){
            int con=0;
            if(v0.empty()) v0.push_back(token);
            for(int x:v0){if(token==x)con++;}
            if(con==0) v0.push_back(token);
            v.push_back(token);
            number[token]=0;
        }
    }
        for(int i:v){number[i]++;}
        for(int n:v0){
            cout << n << " " << number[n] << "\n";}

}