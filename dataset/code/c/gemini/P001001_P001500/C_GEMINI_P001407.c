#include <stdlib.h>

int cmpIntDoubled(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* findOriginalArray(int* changed, int changedSize, int* returnSize) {
    if (changedSize % 2 != 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(changed, changedSize, sizeof(int), cmpIntDoubled);

    int count[200005] = {0};
    for (int i = 0; i < changedSize; i++) count[changed[i]]++;

    int* res = (int*)malloc((changedSize / 2) * sizeof(int));
    int idx = 0;

    for (int i = 0; i < changedSize; i++) {
        int x = changed[i];
        if (count[x] == 0) continue;
        if (2 * x > 200000 || count[2 * x] == 0) {
            free(res);
            *returnSize = 0;
            return NULL;
        }
        res[idx++] = x;
        count[x]--;
        count[2 * x]--;
    }
    *returnSize = idx;
    return res;
}