#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string line;
    vector <int> v1 = {32,97,100,103,106,109,112,116,119};
    vector <int> v2 = {98,101,104,107,110,113,117,120};
    vector <int> v3 = {99,102,105,108,111,114,118,121};
    vector <int> v4 = {115,122};
    int T,index=0,m;
    cin >> T;
    m=T+1;
    while(m--){
        getline(cin, line);
        int s=0;
        for(int i=0; i<line.size(); i++){
            if(binary_search(v1.begin(),v1.end(),(int)line[i])) s++;
            else if(binary_search(v2.begin(),v2.end(),(int)line[i])) s+=2;
            else if(binary_search(v3.begin(),v3.end(),(int)line[i])) s+=3;
            else if(binary_search(v4.begin(),v4.end(),(int)line[i])) s+=4;
            else continue;
        }
        if(index==0) index++;
        else {cout << "Case #" << index << ": " << s << "\n"; 
        index++;}
    }
    return 0;
}