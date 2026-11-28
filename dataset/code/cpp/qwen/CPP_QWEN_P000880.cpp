#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;
    if (x < 0) {
        cout << "false" << endl;
        return 0;
    }
    long long rev = 0, orig = x;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    cout << (rev == orig ? "true" : "false") << endl;
    return 0;
}
