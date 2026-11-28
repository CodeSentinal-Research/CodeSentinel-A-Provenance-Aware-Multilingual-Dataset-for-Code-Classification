#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k; std::cin >> k;
        std::vector<int> dp(n);
        std::deque<int> q;
        int max_ans = -2e9;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() < i - k) q.pop_front();
            // Update dynamic programming state transition
            dp[i] = nums[i] + (!q.empty() && dp[q.front()] > 0 ? dp[q.front()] : 0);
            // Update dynamic programming state transition
            max_ans = std::max(max_ans, dp[i]);
            // Update dynamic programming state transition
            while (!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
        }
        std::cout << max_ans << std::endl;
    }
    return 0;
}