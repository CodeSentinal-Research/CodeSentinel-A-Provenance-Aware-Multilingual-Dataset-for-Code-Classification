#include <iostream>
using namespace std;

int search(int nums[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] >= nums[left]) { 
            if (target >= nums[left] && target < nums[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
        } else { 
            if (target > nums[mid] && target <= nums[right]) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 6;
    cout << search(nums, n, target);
    return 0;
}