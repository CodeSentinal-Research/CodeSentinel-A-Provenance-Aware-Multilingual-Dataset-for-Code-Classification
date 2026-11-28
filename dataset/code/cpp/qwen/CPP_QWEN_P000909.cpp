#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<vector<long long>> C(n + 1, vector<long long>(r + 1, 0));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= min(i, r); ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    cout << C[n][r] << endl;
    return 0;
}
