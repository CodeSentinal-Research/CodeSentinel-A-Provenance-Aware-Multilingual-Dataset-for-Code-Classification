int minimumSize(int* nums, int numsSize, int maxOperations) {
    int left = 1, right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) right = nums[i];
    }
    int ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        long long ops = 0;
        for (int i = 0; i < numsSize; i++) {
            ops += (nums[i] - 1) / mid;
        }
        if (ops <= maxOperations) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}