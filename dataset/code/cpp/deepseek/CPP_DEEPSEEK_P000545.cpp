#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < n; i++) {
        dp[i] = nums[i];
        for (int j = 0; j < i && j <= k; j++) {
            if (dp[j] > 0) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the max difference: ";
    cin >> k;
    vector<int> nums(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxSum = constrainedSubsetSum(nums, k);
    cout << "Maximum possible sum is: " << maxSum << endl;

    return 0;
}