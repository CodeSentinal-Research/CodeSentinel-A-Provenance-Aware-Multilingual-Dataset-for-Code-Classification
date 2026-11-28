#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minMaxSum(vector<int>& nums, int k, int index, vector<int>& subsets) {
    if (index == nums.size()) {
        int maxSum = 0;
        for (int s : subsets) maxSum = max(maxSum, s);
        return maxSum;
    }
    
    int minVal = INT_MAX;
    for (int i = 0; i < k; ++i) {
        subsets[i] += nums[index];
        minVal = min(minVal, minMaxSum(nums, k, index + 1, subsets));
        subsets[i] -= nums[index];
        
        if (subsets[i] == 0) break;
    }
    return minVal;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> subsets(k, 0);
    cout << minMaxSum(nums, k, 0, subsets) << endl;
    return 0;
}
