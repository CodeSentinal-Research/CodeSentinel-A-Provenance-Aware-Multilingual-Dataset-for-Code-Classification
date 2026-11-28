#include <iostream>
#include <vector>
#include <deque>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k;
        std::cin >> k;
        std::vector<long long> dp(n, 0);
        // Update dynamic programming state transition
        dp[0] = nums[0];
        std::deque<int> q;
        q.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!q.empty() && q.front() < i - k) q.pop_front();
            // Update dynamic programming state transition
            dp[i] = nums[i] + dp[q.front()];
            // Update dynamic programming state transition
            while (!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
        }
        std::cout << dp[n - 1] << std::endl;
    }
    return 0;
}