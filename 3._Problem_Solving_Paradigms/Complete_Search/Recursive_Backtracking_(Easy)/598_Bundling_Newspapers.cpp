#include <bits/stdc++.h>
using namespace std; 

vector<string> newspapers; 
int n, a, b, g;
vector <string> q;
void bt(int idx){
    if(q.size()==g){
        cout << q.front();
        for(int l=1; l < g; ++l) cout << ", " << q[l];
        cout << "\n";
        return;
    }
    for(int i=idx; i < newspapers.size(); ++i){
        q.push_back(newspapers[i]);
        bt(i+1);
        q.pop_back();
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; 
  string s, token, aa, bb ,newspaper; 
  cin>>t;
  cin.ignore();
  cin.ignore();
  while(t--){ 
    newspapers.clear(); 
    n=0; 
    a=0; 
    b=0; 
    getline(cin, s);
    q.clear();
    while(getline(cin, newspaper)) {
      if (newspaper.empty()) break;
      newspapers.emplace_back(newspaper);
    }

    stringstream ss(s);
    int count = 0;
    while (ss >> token) {
      if (count == 0) aa = token;
      if (count == 1) bb = token;
      ++count;
    }
    if (count == 1) {
      if (aa[0] == '*') {
        for(int k=1; k <= newspapers.size(); ++k){
            g = k;
            cout << "Size "<< k << "\n";
            bt(0);
            cout << "\n";
        }

      } 
      else{
        n = stoi(aa);
        g =  n;
        cout << "Size "<< n << "\n";
        bt(0);
        cout << "\n";
      }
    } else {
      a = stoi(aa);
      b = stoi(bb);
      for(int k=a; k <= b; ++k){
        g = k;
        cout << "Size "<< k << "\n";
        bt(0);
        cout << "\n";
      }
    }
    if (t) cout << "\n";
  }
}