#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& nums, int k) {
    int missing = 0, i = 1, n = nums.size();
    while (missing < k) {
        if (i > nums[missing]) {
            missing++;
        } else if (missing > 0 && i == nums[missing - 1]) {
            missing++;
        } else {
            i++;
        }
    }
    return i;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << findKthPositive(nums, k);
    return 0;
}