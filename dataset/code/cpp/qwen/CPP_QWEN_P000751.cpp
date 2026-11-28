#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(vector<int>& nums, int index, int target, int currentSum) {
    if (index == nums.size()) {
        return (currentSum == target) ? 1 : 0;
    }
    // Include
    int include = countSubsequences(nums, index + 1, target, currentSum + nums[index]);
    // Exclude
    int exclude = countSubsequences(nums, index + 1, target, currentSum);
    return include + exclude;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> target;
    
    cout << countSubsequences(nums, 0, target, 0) << endl;
    return 0;
}
