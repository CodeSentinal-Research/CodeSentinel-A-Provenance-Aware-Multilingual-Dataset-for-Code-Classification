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
    long long A, M, B, N;
    cin >> A >> M >> B >> N;
    
    long long x, y;
    long long g = extendedGcd(M, N, x, y);
    
    if ((B - A) % g != 0) {
        cout << -1 << endl;
    } else {
        long long lcm = M / g * N;
        long long sol = (A + M * ((x * ((B - A) / g)) % N)) % lcm;
        if (sol < 0) sol += lcm;
        cout << sol << " " << lcm << endl;
    }
    return 0;
}
