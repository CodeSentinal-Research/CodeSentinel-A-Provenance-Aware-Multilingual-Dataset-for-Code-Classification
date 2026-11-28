#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;
    long long rev = 0;
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    while (x > 0) {
        if (rev > INT_MAX / 10) {
            cout << 0 << endl;
            return 0;
        }
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    if (neg) rev = -rev;
    if (rev < INT_MIN || rev > INT_MAX) cout << 0 << endl;
    else cout << rev << endl;
    return 0;
}
