#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int b,s;
    cin >> b;
    for(int r=1; r<=b; ++r){
        cin >> s;
        vector <int> A;
        for(int i=1; i<s; ++i){int k; cin >> k; A.push_back(k);}
        int n = A.size(), sum = 0, start = 0, l=0, end = 0, s = 0, ans = INT16_MIN, maxl = 0;
        int in=0, en=0;
        for(int i = 0; i < n; ++i) {
		    sum += A[i];
            if (ans == sum) {
                if (i - s > end - start) start = s, end = i;
            }
		    if (ans < sum) {
                start = s; end = i; ans = sum;
            }
		    if (sum < 0) {s = i + 1; sum = 0;}
	    } 
        if(ans < 0) {cout << "Route " << r << " has no nice parts\n"; continue;}
        cout << "The nicest part of route " << r << " is between stops " << start+1 << " and " << end+2 << "\n";
    }
}