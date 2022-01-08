// O(n^2)
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
struct elephant{
  int s;
  int w;
  int id;
};

bool order( elephant &a,  elephant &b){
  //if(a.w != b.w){
    //return a.w <b.w; 
  //}
  return a.s>b.s; 
}

int main() {
  int ind=0;
  vector <elephant> v;
  int S, W;
  while(cin >> W >> S){
    elephant e;
    e.s = S;
    e.w = W;
    e.id = ++ind;
    v.push_back(e);
  }
  //cout<< "id: " << ind << "\n";
  sort(v.begin(), v.end(), order); 

  ind =v.size(); 

  vi d(ind, 1), p(ind,-1); 
  
	for(int i = 0; i < ind; ++i)
	for(int j = 0; j < i; ++j) {
		if ((v[j].w < v[i].w) && (v[j].s > v[i].s) && d[i] < d[j] + 1) d[i] = d[j] + 1, p[i] = j;
	}
  
	int ans = d[0], pos = 0;
	for(int i = 1 ; i < ind; ++i)	if (d[i] > ans) ans = d[i], pos = i;

	vector <elephant> subseq;

	while(pos != -1) {subseq.push_back(v[pos]); pos = p[pos];}

	reverse(subseq.begin(), subseq.end());

	cout << subseq.size() << "\n";
	for(auto &s: subseq) cout << s.id  << "\n";

	return 0;
}
