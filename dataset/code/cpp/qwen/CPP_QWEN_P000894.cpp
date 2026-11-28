#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long A, B;
    cin >> A >> B;
    cout << gcd(A, B) << endl;
    return 0;
}
