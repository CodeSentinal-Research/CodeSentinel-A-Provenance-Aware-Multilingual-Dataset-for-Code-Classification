#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long lcm_ab = (a * b) / gcd(a, b);
    cout << (lcm_ab * c) / gcd(lcm_ab, c) << endl;
    return 0;
}
