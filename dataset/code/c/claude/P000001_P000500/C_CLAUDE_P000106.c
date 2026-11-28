#include <stdlib.h>
int* reverseArray(int* nums, int n) {
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[i] = nums[n - 1 - i];
    return res;
}
