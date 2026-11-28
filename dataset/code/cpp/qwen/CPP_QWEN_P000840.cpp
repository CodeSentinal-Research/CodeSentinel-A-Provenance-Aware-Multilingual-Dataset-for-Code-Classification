#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSplitBags(const vector<int>& nums, int maxOperations, int maxSize) {
    int operations = 0;
    for (int num : nums) {
        if (num > maxSize) {
            operations += (num - 1) / maxSize; // Equivalent to ceil(num/maxSize) - 1
        }
        if (operations > maxOperations) return false;
    }
    return true;
}

int main() {
    int n, maxOperations;
    cin >> n >> maxOperations;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canSplitBags(nums, maxOperations, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
