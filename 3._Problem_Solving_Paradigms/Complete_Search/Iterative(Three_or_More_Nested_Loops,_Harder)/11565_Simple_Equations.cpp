#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B,C;
    cin >> N;
    while (N--){
        cin >> A >> B >> C;
        bool sol = false; int x,y,z;
        for(x=-22; (x <= 22) && !sol; ++x){
            if(x*x <= C){
                for(y=-100; (y <= 100) && !sol; ++y ){
                    if((y != x) && (x*x + y*y <= C)){
                        for(z=-100; (z <= 100) && !sol; ++z){
                            if((z!=x) && (z != y) && (x+y+z == A) && (x*y*z==B) && (x*x + y*y + z*z == C)){
                                vector<int> v = {x,y,z};
                                sort(v.begin(), v.end());
                                cout << v[0] << " " << v[1] << " " << v[2] << "\n";
                                sol =true;
                            }
                        }
                    }
                }
            }
        }
        if(!sol) cout << "No solution.\n";
    }
}