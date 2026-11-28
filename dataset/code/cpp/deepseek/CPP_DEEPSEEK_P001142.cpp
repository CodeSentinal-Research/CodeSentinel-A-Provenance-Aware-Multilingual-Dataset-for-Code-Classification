Here is the C++ code for the problem:

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = 0;
    for(int num : nums) {
        total += num;
    }
    if(total % 2 != 0) {
        return false;
    }
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for(int num : nums) {
        for(int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    return dp[target];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if(canPartition(nums)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

This code uses dynamic programming to solve the problem. It creates a boolean vector `dp` where `dp[i]` is `true` if it's possible to get a sum of `i` with the given numbers. It iterates over the given numbers and for each number, it checks all possible sums from `target` to `num`. If it's possible to get a sum of `i`, it updates `dp[i]` to `true`. If `dp[i]` is already `true`, it means we can get a sum of `i`, so it returns `true`. If `dp[i]` is not `true`, it means we can't get a sum of `i`, so it returns `false`.