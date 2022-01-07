#include <bits/stdc++.h> 
using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int contador, u, aux, index, cont, n;
    int foo [3000];
    
    while(cin >> contador){
        index = 0;
        cont = contador; 
        while(contador--){
            cin >> u;
            foo[index++] = u;
        }
    int dif[cont-1];
    for(int i=0; i < cont-1; i++) dif[i] = abs(foo[i]-foo[i+1]);
    aux=0;
    sort(dif, dif+cont-1);
    //for(int i = 0; i < cont - 1 ; i++) 
      //  cout << dif[i] << " ";
    //cout << "\n";
    int d [3000];
    bool flag = true;
    for(int y=0; y < cont; y++) d[y] = y+1;
    for(int b=0; b < cont-1; b++){
       // cout << "d[b] is: " << d[b] << "\n";
        //cout << "dif[b] is: " << dif[b] << "\n";
        if(d[b] != dif[b]) {
            flag = false;
            break;
        }
    }
    if(flag)  cout << "Jolly\n";
    else cout << "Not jolly\n";
    }
    return 0;   
    }