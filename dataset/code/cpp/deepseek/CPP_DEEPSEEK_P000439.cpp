Here is a simple C++ solution for the problem:

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] >= nums[left]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target <= nums[right] && target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << search(nums, target) << "\n";
    return 0;
}

In this code, we are implementing a binary search to find the target in the rotated sorted array. The idea is to find the pivot point (which is the smallest element in the array) and then perform a binary search on both parts of the array. If the target is within the range of the pivot point, we can consider the left part of the array. Otherwise, we can consider the right part.