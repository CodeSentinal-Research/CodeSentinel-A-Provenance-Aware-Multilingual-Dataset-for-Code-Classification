#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int lengths[numsSize], counts[numsSize];
    for (int i = 0; i < numsSize; i++) { lengths[i] = 1; counts[i] = 1; }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 == lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < numsSize; i++) maxLen = MAX(maxLen, lengths[i]);
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (lengths[i] == maxLen) ans += counts[i];
    }
    return ans;
}