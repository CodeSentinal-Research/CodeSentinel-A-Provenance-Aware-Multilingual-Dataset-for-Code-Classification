#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int ans = 1, cur = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            cur++;
            ans = MAX(ans, cur);
        } else {
            cur = 1;
        }
    }
    return ans;
}