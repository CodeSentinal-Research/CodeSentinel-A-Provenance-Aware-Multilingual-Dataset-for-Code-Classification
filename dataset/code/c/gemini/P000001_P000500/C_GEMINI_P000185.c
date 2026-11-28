#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxLength(int* nums, int numsSize) {
    int maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        int zeros = 0, ones = 0;
        for (int j = i; j < numsSize; j++) {
            if (nums[j] == 0) zeros++;
            else ones++;
            if (zeros == ones) {
                maxLen = MAX(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}