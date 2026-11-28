int maxSubArray(int* nums, int n) {
    int maxSum = nums[0], cur = nums[0];
    for (int i = 1; i < n; i++) {
        cur = (nums[i] > cur + nums[i]) ? nums[i] : cur + nums[i];
        if (cur > maxSum) maxSum = cur;
    }
    return maxSum;
}
