#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    int res = nums[0];
    int curMin = 1, curMax = 1;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        if (n == 0) {
            curMin = 1;
            curMax = 1;
            res = MAX(res, 0);
            continue;
        }
        int tmp = curMax * n;
        curMax = MAX(n, MAX(n * curMax, n * curMin));
        curMin = MIN(n, MIN(tmp, n * curMin));
        res = MAX(res, curMax);
    }
    return res;
}