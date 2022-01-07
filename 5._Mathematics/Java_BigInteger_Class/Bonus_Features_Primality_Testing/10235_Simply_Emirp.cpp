#include <iostream>
#include <algorithm>
#include <sstream>  
using namespace std;
namespace patch{
    template < typename T > std::string to_string(const T& n){
        std::ostringstream stm;
        stm << n ;
        return stm.str() ;
    }
}

using u64 = uint64_t;
using u128 = uint64_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    string a ;
    while (cin >> n){
        a = patch::to_string(n);
        reverse(a.begin(), a.end());
        c = stoi(a);
        if (MillerRabin(n) == 0){cout << n << " " << "is not prime." << "\n";}
        else if (n == c &&  MillerRabin(n) == 1){
            cout << n << " " << "is prime." << "\n";
        }
        else if (MillerRabin(n) == 1 && MillerRabin(c) == 1){
            cout << n << " " << "is emirp." << "\n";
        }
        else if (MillerRabin(n) == 1 && MillerRabin(c) != 1){
            cout << n << " " << "is prime." << "\n";
        }
    }
    
}
