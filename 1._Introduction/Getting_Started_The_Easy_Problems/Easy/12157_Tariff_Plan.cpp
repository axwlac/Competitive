#include <iostream>
using namespace std;

int main(){
    int t, index=1;
    cin >> t;
    while(t--){
        int n,s,sum1=0,sum2=0;
        cin >> n;
        while(n--){
            cin >> s;
            sum1 += 10*((s/30)+1);
            sum2 += 15*((s/60)+1);
        } 
        cout << "Case " << index << ": ";
        if(sum1==min(sum1,sum2) && sum2==min(sum1,sum2)) cout << "Mile Juice " << sum2 << "\n";
        else if(sum1==min(sum1,sum2)) cout << "Mile " << sum1 << "\n";
        else if(sum2==min(sum1,sum2)) cout << "Juice " << sum2 << "\n";
        index++;
    }
    return 0;
}