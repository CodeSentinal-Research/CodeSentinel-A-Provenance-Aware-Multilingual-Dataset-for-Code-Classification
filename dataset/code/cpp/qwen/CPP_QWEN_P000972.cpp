#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;
    long long ways = nCr(N, K);
    double prob = ways / pow(2.0, N);
    cout << fixed << setprecision(6) << prob << endl;
    return 0;
}
