#include <stdlib.h>
int cmpC(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int countPairsWithSum(int* nums, int n, int target) {
    int* sorted = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sorted[i] = nums[i];
    qsort(sorted, n, sizeof(int), cmpC);
    int l = 0, r = n - 1, count = 0;
    while (l < r) {
        int s = sorted[l] + sorted[r];
        if (s == target) {
            if (sorted[l] == sorted[r]) {
                int len = r - l + 1;
                count += len * (len - 1) / 2;
                break;
            }
            int lc = 1, rc = 1;
            while (l+lc < r && sorted[l+lc] == sorted[l]) lc++;
            while (r-rc > l && sorted[r-rc] == sorted[r]) rc++;
            count += lc * rc;
            l += lc; r -= rc;
        } else if (s < target) l++;
        else r--;
    }
    free(sorted);
    return count;
}
