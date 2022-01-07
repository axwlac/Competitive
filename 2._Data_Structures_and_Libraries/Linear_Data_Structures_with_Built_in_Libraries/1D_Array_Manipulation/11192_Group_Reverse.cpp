#include <iostream> 
#include <vector>
#include <string> 
using namespace std; 

void reverseStr(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

int main(){
    int g;
    while(cin >> g , g!=0){
        string line,new_line;
        cin>>line;
        int s = line.size()/g;
        for(int i=0;i<line.size();i+=s){
            for(int u=0;u<s;u++){
                new_line += line[u+i];
            }
            reverseStr(new_line);
            cout << new_line;
            new_line="";
        }
        cout << "\n";
    }
}