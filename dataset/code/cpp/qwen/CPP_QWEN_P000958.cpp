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
    long long A, B;
    cin >> A >> B;
    long long x, y;
    long long g = extendedGcd(A, B, x, y);
    
    // Adjust x to be smallest positive
    // x = x0 + k * (B/g)
    long long step = B / g;
    x = x % step;
    if (x <= 0) x += step;
    
    // Recalculate y
    y = (g - A * x) / B;
    
    cout << x << " " << y << endl;
    return 0;
}
