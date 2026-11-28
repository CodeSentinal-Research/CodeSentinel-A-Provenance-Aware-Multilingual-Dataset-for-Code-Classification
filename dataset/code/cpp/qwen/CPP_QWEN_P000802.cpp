#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, threshold;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    cin >> threshold;

    // Compute 2D Prefix Sum
    vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    auto getSum = [&](int r1, int c1, int r2, int c2) -> long long {
        r1++; c1++; r2++; c2++;
        return prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
    };

    int maxSide = 0;
    // Binary search on side length or just iterate since N,M <= 300
    for (int k = 1; k <= min(N, M); ++k) {
        bool found = false;
        for (int i = 0; i + k - 1 < N; ++i) {
            for (int j = 0; j + k - 1 < M; ++j) {
                if (getSum(i, j, i + k - 1, j + k - 1) <= threshold) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) maxSide = k;
        else break; // Since sums are non-negative, larger squares will also exceed threshold if smaller ones don't fit? 
                    // Actually not necessarily monotonic for arbitrary submatrices, but for fixed top-left it is.
                    // However, we want ANY square. If no square of size k exists, a square of size k+1 might still exist? 
                    // No, if a square of size k+1 has sum <= T, its top-left kxk sub-square also has sum <= T (since values >= 0).
                    // So if no kxk works, no (k+1)x(k+1) works.
    }

    cout << maxSide << endl;
    return 0;
}
