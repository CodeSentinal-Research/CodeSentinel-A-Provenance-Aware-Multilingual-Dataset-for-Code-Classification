Here is a simple implementation of the problem using dynamic programming in C++. The idea is to maintain two states: whether or not the current house can be robbed.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    
    vector<int> dp(nums.size()+1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for(int i=2; i<nums.size(); ++i)
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    
    return dp[nums.size()-1];
}

int main() {
    vector<int> nums = {2, 3, 2};
    int k = 3;

    cout << rob(nums) << endl;

    return 0;
}

This code first checks if the given array `nums` is empty or contains only one element. If so, it returns the single element as the minimum capability. 

If the array contains two elements, it returns the maximum of the two elements as the minimum capability.

Then it initializes a dynamic programming array `dp` with the size of `nums.size()+1` and all elements in it set to zero. `dp[0]` and `dp[1]` are then set to the first and second element in `nums`.

Then a loop iterates from the third element in `nums` to the end of `nums`. In each iteration, the maximum of `dp[i-1]` (the maximum capability that can be stolen if the current house is not robbed) and `dp[i-2] + nums[i]` (the maximum capability that can be stolen if the current house is robbed) is stored in `dp[i]`.

Finally, it returns `dp[nums.size()-1]` which is the maximum capability that can be stolen if the last house is not robbed.