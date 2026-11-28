#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    if (C % B == 0 && C % A == 0 && C == A * B / Gcd(A, B)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}