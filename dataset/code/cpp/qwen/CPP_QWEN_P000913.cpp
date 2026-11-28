#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    int n, r, P;
    cin >> n >> r >> P;
    
    vector<long long> fact(n + 1), invFact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i % P;
    
    invFact[n] = power(fact[n], P - 2, P);
    for (int i = n - 1; i >= 0; --i) invFact[i] = invFact[i+1] * (i + 1) % P;
    
    cout << fact[n] * invFact[r] % P * invFact[n-r] % P << endl;
    return 0;
}
