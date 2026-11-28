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

long long crt(const vector<long long>& rem, const vector<long long>& mod) {
    long long x = 0;
    long long M = 1;
    for (long long m : mod) M *= m;
    
    for (int i = 0; i < rem.size(); ++i) {
        long long Mi = M / mod[i];
        long long yi, xi;
        extendedGcd(Mi, mod[i], xi, yi);
        x = (x + rem[i] * Mi * xi) % M;
    }
    return (x % M + M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<long long> rem(N), mod(N);
    for (int i = 0; i < N; ++i) cin >> rem[i];
    for (int i = 0; i < N; ++i) cin >> mod[i];
    
    cout << crt(rem, mod) << endl;
    return 0;
}
