#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestNiceSubarray(int* nums, int numsSize) {
    int usedBits = 0, l = 0, maxLen = 0;

    for (int r = 0; r < numsSize; r++) {
        while ((usedBits & nums[r]) != 0) {
            usedBits ^= nums[l++];
        }
        usedBits |= nums[r];
        maxLen = MAX(maxLen, r - l + 1);
    }
    return maxLen;
}