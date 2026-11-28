#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long l = 0, r = n, res = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (mid * mid <= n) { res = mid; l = mid + 1; }
        else r = mid - 1;
    }
    cout << res << endl;
    return 0;
}
