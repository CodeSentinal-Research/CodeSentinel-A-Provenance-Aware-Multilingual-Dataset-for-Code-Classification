#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lenOfLongIncSubArr(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int maxLen = 1, curLen = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            curLen++;
            maxLen = MAX(maxLen, curLen);
        } else {
            curLen = 1;
        }
    }
    return maxLen;
}