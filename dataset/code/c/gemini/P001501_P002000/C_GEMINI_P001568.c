int longestSubarray(int* nums, int numsSize) {
    int l = 0, zeros = 0;
    for (int r = 0; r < numsSize; r++) {
        if (nums[r] == 0) zeros++;
        if (zeros > 1) {
            if (nums[l] == 0) zeros--;
            l++;
        }
    }
    return numsSize - l - 1;
}