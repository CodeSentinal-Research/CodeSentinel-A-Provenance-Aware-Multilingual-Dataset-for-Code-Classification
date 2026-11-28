#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    long long g = gcd(A, B);
    cout << (C % g == 0 ? "true" : "false") << endl;
    return 0;
}
