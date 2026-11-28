#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool canSplit(const vector<int>& nums, int k, int maxSum) {
    int splits = 1;
    long long currentSum = 0;
    for (int num : nums) {
        if (currentSum + num > maxSum) {
            splits++;
            currentSum = num;
            if (splits > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0LL);
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
