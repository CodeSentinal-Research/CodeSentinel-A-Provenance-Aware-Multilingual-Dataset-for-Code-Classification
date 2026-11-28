#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    long long N;
    cin >> N;
    // Even positions (0, 2, ...) have 5 choices (0,2,4,6,8)
    // Odd positions (1, 3, ...) have 4 choices (2,3,5,7)
    long long evenCount = (N + 1) / 2;
    long long oddCount = N / 2;
    
    long long res = (power(5, evenCount, MOD) * power(4, oddCount, MOD)) % MOD;
    cout << res << endl;
    return 0;
}
