#include <stdlib.h>
int* rotateLeft(int* nums, int n, int k) {
    if (n == 0) return nums;
    k = ((k % n) + n) % n;
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[i] = nums[(i + k) % n];
    return res;
}
