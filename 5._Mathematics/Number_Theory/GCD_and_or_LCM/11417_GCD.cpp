#include <iostream>
using namespace std;

int GCD (int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD (b, a % b);
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, G, i, j; 
    while(cin >> N){
        if (N==0) break;
    
        G=0;
        for(i=1;i<N;i++)
        for(j=i+1;j<=N;j++)
        {G+=GCD(i,j);
        }
        cout << G << "\n"; 
    } 
}

