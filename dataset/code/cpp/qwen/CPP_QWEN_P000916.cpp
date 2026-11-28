#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<long long> der(N + 1, 0);
    if (N >= 0) der[0] = 1;
    if (N >= 1) der[1] = 0;
    for (int i = 2; i <= N; ++i) {
        der[i] = (i - 1) * (der[i-1] + der[i-2]) % MOD;
    }
    cout << der[N] << endl;
    return 0;
}
