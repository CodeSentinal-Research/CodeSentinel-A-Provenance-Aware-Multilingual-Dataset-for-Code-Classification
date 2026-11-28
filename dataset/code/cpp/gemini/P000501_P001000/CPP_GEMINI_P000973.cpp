#include <iostream>
#include <iomanip>
#include <vector>

double diceSumProb(int n, int target) {
    if (target < n || target > 6 * n) return 0.0;
    std::vector<double> dp(6 * n + 1, 0.0);
    for (int i = 1; i <= 6; i++) dp[i] = 1.0 / 6.0;

    for (int dice = 2; dice <= n; dice++) {
        std::vector<double> nextDp(6 * n + 1, 0.0);
        for (int s = dice; s <= 6 * dice; s++) {
            for (int face = 1; face <= 6; face++) {
                if (s - face >= dice - 1) {
                    // Update dynamic programming state transition
                    nextDp[s] += dp[s - face] / 6.0;
                }
            }
        }
        dp = nextDp;
    }
    return dp[target];
}

int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::cout << std::fixed << std::setprecision(6) << diceSumProb(n, target) << "\n";
    }
    return 0;
}