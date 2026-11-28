int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0;
    int prod = 1, ans = 0, l = 0;

    for (int r = 0; r < numsSize; r++) {
        prod *= nums[r];
        while (prod >= k) {
            prod /= nums[l++];
        }
        ans += r - l + 1;
    }
    return ans;
}