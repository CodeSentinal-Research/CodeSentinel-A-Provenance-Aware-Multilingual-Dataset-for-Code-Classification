#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--; c--; // 0-indexed
    
    // dp[step][i][j] = probability of being at (i, j) after step moves
    // Since K<=100 and N<=50, 100*50*50 = 250,000 states. Feasible.
    
    vector<vector<double>> curr(n, vector<double>(n, 0.0));
    curr[r][c] = 1.0;
    
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    for (int step = 0; step < k; ++step) {
        vector<vector<double>> next(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (curr[i][j] > 0) {
                    for (int m = 0; m < 8; ++m) {
                        int ni = i + dr[m];
                        int nj = j + dc[m];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                    }
                }
            }
        }
        curr = next;
    }
    
    double prob = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            prob += curr[i][j];
        }
    }
    
    cout << fixed << setprecision(6) << prob << endl;
    return 0;
}
