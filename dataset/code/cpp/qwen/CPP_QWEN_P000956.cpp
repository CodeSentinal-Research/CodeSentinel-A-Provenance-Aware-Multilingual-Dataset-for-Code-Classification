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
    long long A, B, M;
    cin >> A >> B >> M;
    long long x, y;
    long long g = extendedGcd(A, M, x, y);
    
    if (B % g != 0) {
        cout << -1 << endl;
    } else {
        x = (x * (B / g)) % M;
        x = (x % M + M) % M;
        cout << x << endl;
    }
    return 0;
}
