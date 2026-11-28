#include <vector>
#include <cfloat>

class Solution {
public:
    // Performs search to locate target element within the given collection.
    double optimalSearchTree(std::vector<double>& p, std::vector<double>& q, int n) {
        std::vector<std::vector<double>> e(n + 2, std::vector<double>(n + 2, 0.0));
        std::vector<std::vector<double>> w(n + 2, std::vector<double>(n + 2, 0.0));

        for (int i = 1; i <= n + 1; i++) {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i - 1];
        }

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                e[i][j] = DBL_MAX;
                w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
                for (int r = i; r <= j; r++) {
                    double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (t < e[i][j]) {
                        e[i][j] = t;
                    }
                }
            }
        }
        return e[1][n];
    }
};