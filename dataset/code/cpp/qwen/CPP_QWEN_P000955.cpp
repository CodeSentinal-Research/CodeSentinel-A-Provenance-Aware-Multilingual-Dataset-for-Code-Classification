#include <iostream>
using namespace std;

long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    long long A, M;
    cin >> A >> M;
    long long x, y;
    long long g = extendedGcd(A, M, x, y);
    if (g != 1) cout << -1 << endl;
    else cout << (x % M + M) % M << endl;
    return 0;
}
