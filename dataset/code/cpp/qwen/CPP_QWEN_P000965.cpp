#include <iostream>
#include <vector>
using namespace std;

long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Merge two congruences: x = r1 (mod m1) and x = r2 (mod m2)
bool merge(long long r1, long long m1, long long r2, long long m2, long long &r, long long &m) {
    long long x, y;
    long long g = extendedGcd(m1, m2, x, y);
    if ((r2 - r1) % g != 0) return false;
    
    long long lcm = m1 / g * m2;
    long long diff = r2 - r1;
    long long sol = (x * (diff / g)) % m2;
    r = (r1 + m1 * sol) % lcm;
    m = lcm;
    if (r < 0) r += m;
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<long long> rem(N), mod(N);
    for (int i = 0; i < N; ++i) cin >> rem[i] >> mod[i];
    
    long long r = rem[0], m = mod[0];
    for (int i = 1; i < N; ++i) {
        if (!merge(r, m, rem[i], mod[i], r, m)) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << r << endl;
    return 0;
}
