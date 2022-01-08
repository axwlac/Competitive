#include <bits/stdc++.h>
using namespace std;
vector <int> v;
bool possible = false;
int t ,ops = 0;

void bt(int s){
    if(s == 5) {if(t == 23) possible =  true; return;}
    int no = 0;
    for(int x = s; x < 5; ++x){
        if(no == 0){
            t += v[x];
            bt(x+1);
            t -= v[x];
            no++;
        }
        if(no == 1){
            t -= v[x];
            bt(x+1);
            t += v[x];
            no++;
        }
        if(no == 2){
            t *= v[x];
            bt(x+1);
            t /= v[x];
            no++;
        }
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e, (a||b||c||d||e)){
        v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);v.push_back(e);
        sort(v.begin(), v.end());

        do{
            t = v[0];
            bt(1);
        }while(next_permutation(v.begin(), v.begin()+5));

        v.clear();
        if(possible){cout << "Possible\n"; possible = false; continue;}
        cout << "Impossible\n";
        possible = false;
    }
}