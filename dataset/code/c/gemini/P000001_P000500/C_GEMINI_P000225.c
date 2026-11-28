#include <stdlib.h>
#include <stdbool.h>

struct PairSwap {
    int idx;
    int val;
};

int cmpPairSwap(const void* a, const void* b) {
    return ((struct PairSwap*)a)->val - ((struct PairSwap*)b)->val;
}

int minSwaps(int* nums, int numsSize) {
    struct PairSwap* arrPos = (struct PairSwap*)malloc(numsSize * sizeof(struct PairSwap));
    for (int i = 0; i < numsSize; i++) {
        arrPos[i].idx = i;
        arrPos[i].val = nums[i];
    }
    qsort(arrPos, numsSize, sizeof(struct PairSwap), cmpPairSwap);

    bool* visited = (bool*)calloc(numsSize, sizeof(bool));
    int swaps = 0;

    for (int i = 0; i < numsSize; i++) {
        if (visited[i] || arrPos[i].idx == i) continue;

        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j].idx;
            cycleSize++;
        }

        if (cycleSize > 0) swaps += cycleSize - 1;
    }

    free(arrPos);
    free(visited);
    return swaps;
}