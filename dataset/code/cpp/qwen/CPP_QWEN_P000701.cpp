#include <iostream>
#include <vector>
using namespace std;

int findMinRecursive(const vector<int>& nums, int index, int currentMin) {
    if (index == nums.size()) return currentMin;
    if (nums[index] < currentMin) currentMin = nums[index];
    return findMinRecursive(nums, index + 1, currentMin);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    if (n == 0) return 0;
    cout << findMinRecursive(nums, 0, nums[0]) << endl;
    return 0;
}
