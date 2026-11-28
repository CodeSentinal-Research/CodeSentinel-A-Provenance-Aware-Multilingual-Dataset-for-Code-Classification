#include <stdlib.h>
int cmpF(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* rearrangeAlternately(int* nums, int n) {
    int* sorted = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sorted[i] = nums[i];
    qsort(sorted, n, sizeof(int), cmpF);
    int* res = (int*)malloc(n * sizeof(int));
    int l = 0, r = n - 1, idx = 0, toggle = 1;
    while (l <= r) {
        if (toggle) res[idx++] = sorted[r--];
        else res[idx++] = sorted[l++];
        toggle = !toggle;
    }
    free(sorted);
    return res;
}
