int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    int dp = 0, total = 0;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            dp++;
            total += dp;
        } else {
            dp = 0;
        }
    }
    return total;
}