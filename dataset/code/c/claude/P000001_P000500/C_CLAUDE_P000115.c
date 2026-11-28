#include <stdlib.h>
int* rotateRight(int* nums, int n, int k) {
    if (n == 0) return nums;
    k = ((k % n) + n) % n;
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[(i + k) % n] = nums[i];
    return res;
}
