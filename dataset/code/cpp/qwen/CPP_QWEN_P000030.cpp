#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << (a * b) / gcd(a, b) << endl;
    return 0;
}
