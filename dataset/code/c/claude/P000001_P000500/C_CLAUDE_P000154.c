#include <stdlib.h>
int* findMissingRepeating(int* nums, int n, int* returnSize) {
    *returnSize = 2;  // write through pointer
    int* cnt = (int*)calloc(n + 1, sizeof(int));
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = -1; res[1] = -1;
    for (int i = 0; i < n; i++) { cnt[nums[i]]++; if (cnt[nums[i]] == 2) res[0] = nums[i]; }
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) { res[1] = i; break; }
    free(cnt);
    return res;
}
