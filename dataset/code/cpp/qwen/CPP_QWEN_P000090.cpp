#include <iostream>
using namespace std;

long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    long long res = 1;
    for (int i = 0; i < r; i++) { res *= (n - i); res /= (i + 1); }
    return res;
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}
