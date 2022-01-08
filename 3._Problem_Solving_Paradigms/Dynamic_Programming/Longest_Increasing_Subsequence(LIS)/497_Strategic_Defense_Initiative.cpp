/*#include <bits/stdc++.h> 
using namespace std;
vector <int> arr;
vector <int> index;
vector <int> res;
void sub(int idx){
    res.push_back(arr[idx]);
    if(index[idx]==-1) return;
    sub(index[idx]);
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, m;
    string line;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--){
        while (getline(cin, line), line!=""){
            stringstream s(line);
            s >> m;
            arr.push_back(m);
        }
        int n = arr.size();
        vector <int> lenght (n);
        index.assign(n,-1);
        for(int k=0; k < n ; ++k){
            lenght[k] = 1;
            for(int i=0; i < k ; ++i){
                if(arr[i] < arr[k]){
                    if(lenght[k] <= lenght[i] + 1) index[k] = i;
                    lenght[k] = max(lenght[k], lenght[i]+1);
                }
            }
        }
        int idx, maxi=-1;
        for(int i=0; i < n; ++i){
            if(maxi < lenght[i]){
                maxi = lenght[i];
                idx = i;
            }
        }
        cout << "Max hits: " << maxi << "\n";
        sub(idx);
        reverse(res.begin(), res.end());
        for(int i: res) cout << i << "\n";
        arr.clear(); index.clear(); res.clear();
        if(t) cout << "\n";
    }   
}*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    while ( T-- )
    {
        vector<int> M;
        string s;
        while (getline(cin, s) && s != "")
        { 
            stringstream ss(s);
            int missle;

            ss >> missle;
            M.push_back(missle);
        }

        // O(n^2) DP.
        vector<int> LIS(M.size(), 1);
        vector<int> path(M.size(), -1);
        LIS[0] = 1;      
        for (size_t i = 1; i < M.size(); ++i)
            for (size_t j = 0; j < i; ++j)
            {
                int l = M[j] < M[i]? LIS[j] + 1 : 0;
                if (l > LIS[i])
                {
                    LIS[i] = l;
                    path[i] = static_cast<int>(j);
                }
            }
        // Print the path.
        int i = static_cast<int>(distance(LIS.begin(),
                                          max_element(LIS.begin(), LIS.end()) 
                                          )
                                 );
        vector<int> print(1, M[i]);
        while (path[i] != -1)
        {
            i = path[i];
            print.insert(print.begin(), M[i]);
        }
        cout << "Max hits: " << print.size() << endl;
        copy(print.begin(), print.end(), ostream_iterator<int>(cout, "\n"));
        if (T)
            cout << endl;
    }
    return 0;
}