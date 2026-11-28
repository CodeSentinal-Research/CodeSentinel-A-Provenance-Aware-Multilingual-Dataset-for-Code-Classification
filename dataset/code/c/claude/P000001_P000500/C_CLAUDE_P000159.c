int smallestSubarraySum(int* nums, int n) {
    int minSum = nums[0], cur = nums[0];
    for (int i = 1; i < n; i++) {
        cur = (nums[i] < cur + nums[i]) ? nums[i] : cur + nums[i];
        if (cur < minSum) minSum = cur;
    }
    return minSum;
}
