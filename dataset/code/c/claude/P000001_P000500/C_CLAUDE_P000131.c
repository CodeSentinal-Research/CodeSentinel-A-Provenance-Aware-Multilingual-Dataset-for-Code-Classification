#include <stdlib.h>
int* findLeaders(int* nums, int n, int* returnSize) {
    if (n == 0) { *returnSize = 0; return NULL; }
    int* tmp = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    int maxRight = nums[n - 1];
    tmp[cnt++] = maxRight;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] >= maxRight) { maxRight = nums[i]; tmp[cnt++] = maxRight; }
    }
    int* res = (int*)malloc(cnt * sizeof(int));
    for (int i = 0; i < cnt; i++) res[i] = tmp[cnt - 1 - i];
    free(tmp);
    *returnSize = cnt;  // write through pointer
    return res;
}
