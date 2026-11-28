#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;
    vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int val;
            cin >> val;
            prefix[i][j] = val + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    cin >> Q;
    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // Adjust to 1-based if input is 0-based, assuming 0-based input for queries
        r1++; c1++; r2++; c2++;
        long long sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
        cout << sum << endl;
    }
    return 0;
}
