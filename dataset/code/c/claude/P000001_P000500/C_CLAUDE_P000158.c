long long largestSumIncreasing(int* nums, int n) {
    if (n == 0) return 0;
    long long best = nums[0], cur = nums[0];
    for (int i = 1; i < n; i++) {
        cur = (nums[i] > nums[i-1]) ? cur + nums[i] : nums[i];
        if (cur > best) best = cur;
    }
    return best;
}
