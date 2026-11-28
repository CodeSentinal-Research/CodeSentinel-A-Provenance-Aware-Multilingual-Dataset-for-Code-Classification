#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestAlternatingSubarray(int* nums, int numsSize, int threshold) {
    int maxLen = 0, l = 0;

    while (l < numsSize) {
        if (nums[l] % 2 == 0 && nums[l] <= threshold) {
            int r = l;
            while (r + 1 < numsSize && nums[r + 1] <= threshold && (nums[r] % 2) != (nums[r + 1] % 2)) {
                r++;
            }
            maxLen = MAX(maxLen, r - l + 1);
            l = r + 1;
        } else {
            l++;
        }
    }
    return maxLen;
}