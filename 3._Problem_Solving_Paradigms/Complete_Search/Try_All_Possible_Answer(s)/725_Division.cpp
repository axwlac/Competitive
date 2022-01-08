#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, index=0;
    while(cin>>N, N!=0){
        if(index++)cout << "\n";
        bool f=true;
        for(int fghij = 1234; fghij <= 98765/N; ++fghij){
            int abcde = fghij*N;
            int tmp, used = (fghij < 10000);
            tmp = abcde; while (tmp){ used |= 1<<(tmp%10); tmp /= 10; }
            tmp = fghij; while (tmp){ used |= 1<<(tmp%10); tmp /= 10; }
            if(used == (1<<10)-1){
                printf("%05d / %05d = %d\n", abcde, fghij, N);
                f=false;
            }
        }
        if(f) cout << "There are no solutions for " << N << ".\n";
    }
}