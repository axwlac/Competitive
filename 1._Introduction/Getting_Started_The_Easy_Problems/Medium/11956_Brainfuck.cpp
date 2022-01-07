#include <iostream>
#include <iomanip>
using namespace std;
int mod(int a, int b){
    //This works for this problem because b is >= a.
    return (((a%b) + b) % b);
}

int main(){
    int t,index=1;
    string s;
    cin>>t;
    while(t--){
        int pointer=0;
        int display [100] = {0};
        cin>>s;
        for(int i=0;i<s.size();i++){
            /*cout <<"s[i]: " <<s[i] <<"\n";*/
            if(s[i]=='.') continue;
            else if(s[i]=='<') {/*cout << "p antes: " << pointer ;*/pointer = mod((pointer-1),100); /*cout << " p después: " << pointer << "\n";*/}
            else if(s[i]=='>') {/*cout << "p antes: " << pointer ;*/pointer = mod((pointer+1),100); /*cout << " p después: " << pointer << "\n";*/}
            else if(s[i]=='+') {/*cout << "d antes: " << display[pointer];*/display[pointer] = mod(display[pointer]+1,256);/*cout << " d después: " << display[pointer] << "\n";*/}
            else if(s[i]=='-') {/*cout << "d antes: " << display[pointer];*/display[pointer] = mod(display[pointer]-1,256);/*cout << " d después: " << display[pointer] << "\n";*/}
        }
        cout << "Case "<< to_string(index++) <<": " ;
        for(int i=0;i<100;i++){if(i!=99)cout << internal << setfill('0') << hex << setw(2) << uppercase << display[i] << " ";
        else cout << internal << setfill('0') << hex << setw(2) << uppercase << display[i] ; }
        cout << "\n";
    }
}