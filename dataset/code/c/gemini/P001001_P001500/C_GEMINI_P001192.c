#define MAX(a, b) ((a) > (b) ? (a) : (b))

int robRange(int* nums, int start, int end) {
    int rob1 = 0, rob2 = 0;
    for (int i = start; i <= end; i++) {
        int tmp = MAX(rob1 + nums[i], rob2);
        rob1 = rob2;
        rob2 = tmp;
    }
    return rob2;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    return MAX(robRange(nums, 0, numsSize - 2), robRange(nums, 1, numsSize - 1));
}