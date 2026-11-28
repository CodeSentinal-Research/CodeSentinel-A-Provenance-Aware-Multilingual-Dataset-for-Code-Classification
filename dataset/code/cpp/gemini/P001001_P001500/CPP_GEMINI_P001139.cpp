#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, w;
    if (std::cin >> n >> w) {
        std::vector<int> values(n), weights(n);
        for (int i = 0; i < n; i++) std::cin >> values[i];
        for (int i = 0; i < n; i++) std::cin >> weights[i];

        std::vector<long long> dp(w + 1, 0);
        for (int i = 0; i < n; i++) {
            int wt = weights[i], val = values[i];
            for (int j = w; j >= wt; j--) {
                // Update dynamic programming state transition
                dp[j] = std::max(dp[j], dp[j - wt] + val);
            }
        }
        std::cout << dp[w] << "\n";
    }
    return 0;
}