#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxK(int* nums, int numsSize) {
    int seen[2005] = {0};
    int offset = 1000;
    for (int i = 0; i < numsSize; i++) seen[nums[i] + offset] = 1;

    int maxK = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0 && seen[-nums[i] + offset]) {
            maxK = MAX(maxK, nums[i]);
        }
    }
    return maxK;
}