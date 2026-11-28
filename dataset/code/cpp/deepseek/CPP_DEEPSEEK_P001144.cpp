#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << longestIncreasingSubsequence(nums) << endl;
    return 0;
}
This C++ code implements the Longest Increasing Subsequence problem. The algorithm works by creating a dynamic programming (DP) table where each element dp[i] represents the length of the longest increasing subsequence ending with nums[i]. For each nums[i], it checks all its preceding nums[j], and if nums[i] is greater than nums[j], it updates dp[i] to the maximum of dp[i] and dp[j] + 1. Finally, it returns the maximum element in dp, which represents the length of the longest increasing subsequence.