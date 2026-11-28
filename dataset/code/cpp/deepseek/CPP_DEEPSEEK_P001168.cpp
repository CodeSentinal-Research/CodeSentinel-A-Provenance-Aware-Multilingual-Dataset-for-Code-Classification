#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    if (K == 1) {
        if (N == 1) {
            cout << 1;
            return 0;
        }
        else if (N == 2) {
            cout << 2;
            return 0;
        }
        else {
            cout << 3;
            return 0;
        }
    }

    long long mod = 1000000007;
    long long x = 2;
    long long y = 4;
    long long z = 2;

    for (int i = 4; i <= N; i++) {
        long long temp = y;
        y = z;
        z = (x + y) % mod;
        x = temp;
    }

    cout << z;

    return 0;
}