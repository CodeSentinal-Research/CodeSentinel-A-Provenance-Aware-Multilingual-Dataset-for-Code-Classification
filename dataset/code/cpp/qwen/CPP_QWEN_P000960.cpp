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
    long long A, B, C;
    cin >> A >> B >> C;
    long long x, y;
    long long g = extendedGcd(A, B, x, y);
    
    if (C % g != 0) {
        cout << -1 << endl;
    } else {
        x *= (C / g);
        y *= (C / g);
        cout << x << " " << y << endl;
    }
    return 0;
}
