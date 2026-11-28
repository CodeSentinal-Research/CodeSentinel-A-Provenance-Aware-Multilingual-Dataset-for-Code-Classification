#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minProductSubarray(int* nums, int numsSize) {
    int minProd = nums[0], maxProd = nums[0], ans = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int x = nums[i];
        int p1 = minProd * x, p2 = maxProd * x;
        minProd = MIN(x, MIN(p1, p2));
        maxProd = MAX(x, MAX(p1, p2));
        ans = MIN(ans, minProd);
    }
    return ans;
}