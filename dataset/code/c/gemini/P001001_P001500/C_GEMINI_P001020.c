#include <stdlib.h>
#include <limits.h>

typedef struct {
    int val;
    int group;
} Pair;

int cmpPairs(const void* a, const void* b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += numsColSize[i];
    Pair* pairs = (Pair*)malloc(total * sizeof(Pair));
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            pairs[idx].val = nums[i][j];
            pairs[idx].group = i;
            idx++;
        }
    }
    qsort(pairs, total, sizeof(Pair), cmpPairs);

    int* counts = (int*)calloc(numsSize, sizeof(int));
    int unique = 0, l = 0;
    int bestL = pairs[0].val, bestR = pairs[total - 1].val;

    for (int r = 0; r < total; r++) {
        counts[pairs[r].group]++;
        if (counts[pairs[r].group] == 1) unique++;

        while (unique == numsSize) {
            if (pairs[r].val - pairs[l].val < bestR - bestL) {
                bestL = pairs[l].val;
                bestR = pairs[r].val;
            }
            counts[pairs[l].group]--;
            if (counts[pairs[l].group] == 0) unique--;
            l++;
        }
    }
    free(pairs);
    free(counts);
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = bestL; res[1] = bestR;
    return res;
}