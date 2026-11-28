#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

int main() {
    long long A, B, X, Y;
    cin >> A >> B >> X >> Y;
    long long g = gcd(A, B);
    cout << (A * X + B * Y == g ? "true" : "false") << endl;
    return 0;
}
