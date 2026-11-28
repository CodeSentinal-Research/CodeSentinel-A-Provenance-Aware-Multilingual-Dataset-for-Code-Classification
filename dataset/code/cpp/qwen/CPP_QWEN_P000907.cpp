#include <iostream>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long A, B, M;
    cin >> A >> B >> M;
    cout << power(A, B, M) << endl;
    return 0;
}
