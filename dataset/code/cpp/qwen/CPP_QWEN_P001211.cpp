#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k, int target, int idx, vector<int>& sums) {
    if (idx == nums.size()) {
        for (int s : sums) {
            if (s != target) return false;
        }
        return true;
    }
    
    for (int i = 0; i < k; ++i) {
        if (sums[i] + nums[idx] <= target) {
            sums[i] += nums[idx];
            if (canPartitionKSubsets(nums, k, target, idx + 1, sums)) return true;
            sums[i] -= nums[idx];
        }
        // Optimization: if sum is 0, break to avoid duplicate empty subsets
        if (sums[i] == 0) break;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }
    
    if (sum % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    int target = sum / k;
    vector<int> sums(k, 0);
    
    // Sort descending for better pruning
    sort(nums.rbegin(), nums.rend());
    
    cout << (canPartitionKSubsets(nums, k, target, 0, sums) ? "YES" : "NO") << endl;
    return 0;
}
