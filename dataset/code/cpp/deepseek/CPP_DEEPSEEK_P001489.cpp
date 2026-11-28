Here is the code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= nums[i]; --j) {
            dp[j] = (dp[j] + dp[j - nums[i]]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= target; ++i) {
        ans = (ans + dp[i]) % MOD;
    }

    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << solve(nums, target) << endl;

    return 0;
}

This program uses dynamic programming to solve the problem. The `dp` array stores the number of ways to sum up numbers up to a certain target. The `i`-th element of `dp` is the number of ways to sum up numbers up to `i` (excluding the last number in the subsequence). For each number in the input array, we update the `dp` array by adding the number to all the possible previous targets.

Finally, we sum up all the elements in `dp` and return the result modulo 10^9 + 7.