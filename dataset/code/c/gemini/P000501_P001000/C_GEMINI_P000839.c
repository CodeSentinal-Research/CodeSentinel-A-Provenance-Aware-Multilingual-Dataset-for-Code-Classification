int smallestDivisor(int* nums, int numsSize, int threshold) {
    int left = 1, right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) right = nums[i];
    }
    int ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int total = 0;
        for (int i = 0; i < numsSize; i++) {
            total += (nums[i] + mid - 1) / mid;
        }
        if (total <= threshold) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}