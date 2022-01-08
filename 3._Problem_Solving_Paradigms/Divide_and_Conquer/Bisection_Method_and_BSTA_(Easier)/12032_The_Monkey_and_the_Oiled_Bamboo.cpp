#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n, tcn = 1; cin >> t;
    while(t--){
        cin >> n;
        vector <int> a(n+1);
        int k =-1e9;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            k = max(k, a[i+1] - a[i]);
        }
        int ans = k;
        cout << "Case " << tcn++ << ": ";
        for(int i = 1; i <= n; i++) {
            if(a[i]-a[i-1] == k)
                k--;
            else if(a[i]-a[i-1] > k) {
                ans++;
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}