#include <iostream>
using namespace std;

long long mulmod(long long a, long long b, long long mod) {
    if (b == 0) return 0;
    long long res = mulmod(a, b / 2, mod);
    res = (res + res) % mod;
    if (b % 2 == 1) res = (res + a % mod) % mod;
    return res;
}

int main() {
    long long A, B, M;
    cin >> A >> B >> M;
    cout << mulmod(A, B, M) << endl;
    return 0;
}
