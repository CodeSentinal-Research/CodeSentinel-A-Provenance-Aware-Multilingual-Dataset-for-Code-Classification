#include <stdlib.h>
int cmpI(const void* a, const void* b) { return *(int*)a - *(int*)b; }
long long maxProduct(int* nums, int n) {
    qsort(nums, n, sizeof(int), cmpI);
    long long o1 = (long long)nums[0] * nums[1];
    long long o2 = (long long)nums[n-2] * nums[n-1];
    return o1 > o2 ? o1 : o2;
}
