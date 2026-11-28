#include <stdlib.h>
int cmpPair(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int** findAllPairs(int* nums, int n, int target, int* returnSize, int** returnColumnSizes) {
    int* sorted = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sorted[i] = nums[i];
    qsort(sorted, n, sizeof(int), cmpPair);
    int** res = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));  // write through pointer
    int cnt = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        int s = sorted[l] + sorted[r];
        if (s == target) {
            res[cnt] = (int*)malloc(2 * sizeof(int));
            res[cnt][0] = sorted[l]; res[cnt][1] = sorted[r];
            (*returnColumnSizes)[cnt++] = 2;
            int lv = sorted[l++], rv = sorted[r--];
            while (l < r && sorted[l] == lv) l++;
            while (l < r && sorted[r] == rv) r--;
        } else if (s < target) l++;
        else r--;
    }
    free(sorted);
    *returnSize = cnt;  // write through pointer
    return res;
}
