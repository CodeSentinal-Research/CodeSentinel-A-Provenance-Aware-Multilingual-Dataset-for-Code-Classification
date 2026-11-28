#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0 || target > sum) return false;
    
    vector<int> path(k, target);
    sort(nums.begin(), nums.end(), greater<int>());
    return helper(nums, path, 0, 0, target);
}

bool helper(vector<int>& nums, vector<int>& path, int start, int partial, int target) {
    if (partial == target) return true;
    if (partial > target) return false;
    for (int i = start; i < nums.size(); ++i) {
        if (path[i / partial % path.size()] >= nums[i]) {
            path[i / partial % path.size()] -= nums[i];
            if (helper(nums, path, i + 1, partial + nums[i], target)) return true;
            path[i / partial % path.size()] += nums[i];
        }
    }
    return false;
}

int main() {
    vector<int> nums = {4, 3, 2, 1, 3, 5, 2, 6};
    int k = 4;
    int target = accumulate(nums.begin(), nums.end(), 0);
    target /= k;

    cout << (canPartitionKSubsets(nums, k, target) ? "true" : "false");

    return 0;
}

This C++ solution uses a depth-first search (DFS) approach to solve the problem. It first calculates the target sum of each partition and checks if it can be achieved. If not, it returns false.

Then, the main function initializes the `nums` array, the `k` and `target` variables and calls the `canPartitionKSubsets` function with these variables as arguments.

The `canPartitionKSubsets` function checks if it is possible to partition `nums` into `k` non-empty subsets with the same sum by starting at index `start` and adding each number to the current subset until the partial sum exceeds the target sum.

The `helper` function is a helper function for `canPartitionKSubsets`. It recursively tries to partition the rest of the numbers in the current subset. If it can find a solution, it returns true; otherwise, it continues to try other subsets.

The code finally prints out whether it is possible to partition `nums` into `k` non-empty subsets with the same sum.