#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int k, prod, total;

vector<char> A, B, C, D, E;


// Matrices de entrada
int Q[6], R[6], S[6], T[6], U[6];
int V[6], W[6], X[6], Y[6], Z[6];

bool ok = false;
void bt(string res, int in_line, int line, int cum){
  if(ok) return;
  if (res.size() == 5) {
    cout << res << "\n";
    ok = true;
    return;
  }
  if(k <= prod + cum){// Pasas al siguiente arreglo
    if(line == 0) {
      res += A[in_line];
    } else if (line == 1) {
      res += B[in_line];
    } else if (line == 2) {
      res += C[in_line];
    } else if (line == 3) {
      res += D[in_line];
    } else if (line == 4) {
      res += E[in_line];
    }

    line+=1;

    if(line == 0) {
      prod /= (int) A.size();
    } else if (line == 1) {
      prod /= (int) B.size();
    } else if (line == 2) {
      prod /= (int) C.size();
    } else if (line == 3) {
      prod /= (int) D.size();
    } else if (line == 4) {
      prod /= (int) E.size();
    }

    bt(res , 0, line, cum);
    
  } //pasas a la siguiente fila
  else{// pasas al siguiente caracter
    // meter a cum += prod
    bt(res , in_line+1, line, cum + prod);
  }
}
 
// k = 144  total = 288
// in_line = 0, line= E , prod = 1, cum = 143
  //A: ACDW 4
  //B: BOP 3 
  //C: GMOX 4
  //D: AP 2
  //E: GSU  3
  //res: CPXPU
  // 


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;

  cin >> t;
  string s;
  while(t--) {
    set<char> AA, BB, CC, DD, EE;
    cin >> k;
    bool emp = false;
    prod=1;
    for(int i = 0; i < 6; ++i){
      cin >> s;
      for(int j = 0; j < 5; ++j) {
        if (j == 0) Q[i] = s[j];
        if (j == 1) R[i] = s[j];
        if (j == 2) S[i] = s[j];
        if (j == 3) T[i] = s[j];
        if (j == 4) U[i] = s[j];
      }
    }
    for(int i = 0; i < 6; ++i){
      cin >> s;
      for(int j = 0; j < 5; ++j) {
        if (j == 0) V[i] = s[j];
        if (j == 1) W[i] = s[j];
        if (j == 2) X[i] = s[j];
        if (j == 3) Y[i] = s[j];
        if (j == 4) Z[i] = s[j];
      }
    }
    A.clear();
    B.clear();
    C.clear();
    D.clear();
    E.clear();
    ok = false;
    // Columna A;
    int idx = 0;
    for(int i = 0; i < 6; ++i) {
      for(int j = 0; j < 6; ++j) {
        if (Q[i] == V[j]) AA.insert(Q[i]);
      }
    }

    for(char a: AA) A.emplace_back(a);
    total = A.size();
    if(A.empty()) emp = true;
   // cout << A.size() << "\n";
   // for(char a: A) cout << a << " ";
    //cout << "\n";


    // Columna B;
    for(int i = 0; i < 6; ++i) {
      for(int j = 0; j < 6; ++j) {
        if (R[i] == W[j]) BB.insert(R[i]);
      }
    }
     for(char a: BB) B.emplace_back(a);
     if(B.empty()) emp = true;
    prod *= (int) B.size();

//      //cout << B.size() << "\n";
    //for(char a: B) cout << a << " ";
    //cout << "\n";

    // Columna C
    for(int i = 0; i < 6; ++i) {
      for(int j = 0; j < 6; ++j) {
        if (S[i] == X[j]) CC.insert(S[i]);
      }
    }
     for(char a: CC) C.emplace_back(a);
     if(C.empty()) emp = true;
     prod *= (int) C.size();

      //cout << C.size() << "\n";
    ////for(char a: C) cout << a << " ";
    //cout << "\n";
    
    // Columna D
    for(int i = 0; i < 6; ++i) {
      for(int j = 0; j < 6; ++j) {
        if (T[i] == Y[j]) DD.insert(T[i]);
      }
    }
    
     for(char a: DD) D.emplace_back(a);
     if(D.empty()) emp = true;
     prod *= (int) D.size();
     
     // cout << D.size() << "\n";
    //for(char a: D) cout << a << " ";
    //cout << "\n";
    // Columna E
    for(int i = 0; i < 6; ++i) {
      for(int j = 0; j < 6; ++j) {
        if (U[i] == Z[j]) EE.insert(U[i]);
      }
    }

     for(char a: EE) E.emplace_back(a);
    
     if(E.empty()) emp = true;
    prod *= (int) E.size();
    total *= prod;

      //cout << E.size() << "\n";
    //for(char a: E) cout << a << " ";
    //cout << "\n";
    
    if(emp || total < k) cout << "NO\n";
    else bt("", 0, 0, 0);
    
  }
  

}