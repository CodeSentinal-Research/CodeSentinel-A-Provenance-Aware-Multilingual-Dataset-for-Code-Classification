#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int index, vector<long long>& subsets, long long target) {
    if (index == nums.size()) {
        for (long long s : subsets) {
            if (s != target) return false;
        }
        return true;
    }
    
    for (int i = 0; i < subsets.size(); ++i) {
        if (subsets[i] + nums[index] <= target) {
            subsets[i] += nums[index];
            if (canPartitionKSubsets(nums, index + 1, subsets, target)) return true;
            subsets[i] -= nums[index];
        }
        if (subsets[i] == 0) break;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }
    cin >> k;
    
    if (sum % k != 0) {
        cout << "false" << endl;
        return 0;
    }
    
    long long target = sum / k;
    vector<long long> subsets(k, 0);
    sort(nums.rbegin(), nums.rend());
    
    cout << (canPartitionKSubsets(nums, 0, subsets, target) ? "true" : "false") << endl;
    return 0;
}
