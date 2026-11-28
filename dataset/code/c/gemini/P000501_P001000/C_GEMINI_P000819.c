int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    // Binary search loop to narrow down range
    while (left < right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}