Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

long long countArithmeticSlices(vector<int> &nums) {
    int n = nums.size();
    long long res = 0;
    vector<int> dp(n, 1); 

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] - nums[j] >= nums[j]) { 
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        res += dp[i]; 
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << countArithmeticSlices(nums) << endl;
    return 0;
}

In this code, we use a dynamic programming (DP) approach to solve the problem. The dp array dp[i] represents the number of arithmetic slices ending at index i. For each index i, we iterate through all the previous indices j, and if the difference between the current number and the previous number is greater than or equal to the previous number, we update the dp[i] to be the maximum of dp[i] and dp[j] + 1. Finally, we add up all dp[i] to get the total number of arithmetic slices.