#include <stdlib.h>
int cmpI2(const void* a, const void* b) { return *(int*)a - *(int*)b; }
long long minProduct(int* nums, int n) {
    qsort(nums, n, sizeof(int), cmpI2);
    long long a = (long long)nums[0] * nums[1];
    long long b = (long long)nums[0] * nums[n-1];
    long long c = (long long)nums[n-2] * nums[n-1];
    long long mn = a < b ? a : b;
    return mn < c ? mn : c;
}
