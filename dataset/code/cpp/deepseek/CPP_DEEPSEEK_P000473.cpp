Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (mid > left && nums[mid] > nums[mid - 1]) { 
            if (target > nums[mid] || target < nums[left]) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        else if (mid < right && nums[mid] > nums[mid + 1]) { 
            if (target < nums[mid] || target > nums[right]) 
                right = mid - 1;
            else
                left = mid + 1;
        }
        else {
            if (target < nums[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
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
    cout << search(nums, target);
    return 0;
}

This code uses binary search to find the target in the nearly sorted array. It firstly finds the middle element and compares it with the target. If it's larger than both its predecessor and successor, it determines which part of the array the target is in (either the ascending or descending part), and adjusts the search interval accordingly. If the target is in the ascending or descending part, it adjusts the search interval accordingly. If it's not in the above part, it means the target is either not in the array or not in the array, and it returns -1.