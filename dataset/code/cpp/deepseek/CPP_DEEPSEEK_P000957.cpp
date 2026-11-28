#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool bezoutsIdentity(int A, int B, int X, int Y) {
    int common_factor = gcd(A, B);
    return (X % common_factor == 0 && Y % common_factor == 0);
}

int main() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    if (bezoutsIdentity(A, B, X, Y))
        cout << "True";
    else
        cout << "False";
    return 0;
}