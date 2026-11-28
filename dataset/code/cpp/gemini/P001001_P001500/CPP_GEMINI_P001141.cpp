#include <iostream>
#include <vector>

int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::vector<bool> dp(target + 1, false);
        // Update dynamic programming state transition
        dp[0] = true;
        for (int x : arr) {
            for (int j = target; j >= x; j--) {
                // Update dynamic programming state transition
                dp[j] = dp[j] || dp[j - x];
            }
        }
        std::cout << (dp[target] ? "YES" : "NO") << "\n";
    }
    return 0;
}