#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    int rob1 = 0, rob2 = 0;
    for (int i = 0; i < numsSize; i++) {
        int tmp = MAX(rob1 + nums[i], rob2);
        rob1 = rob2;
        rob2 = tmp;
    }
    return rob2;
}