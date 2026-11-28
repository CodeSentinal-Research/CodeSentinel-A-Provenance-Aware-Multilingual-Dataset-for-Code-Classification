#include <stdlib.h>
int* separateEvenOdd(int* nums, int n) {
    int* res = (int*)malloc(n * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) if (nums[i] % 2 == 0) res[k++] = nums[i];
    for (int i = 0; i < n; i++) if (nums[i] % 2 != 0) res[k++] = nums[i];
    return res;
}
