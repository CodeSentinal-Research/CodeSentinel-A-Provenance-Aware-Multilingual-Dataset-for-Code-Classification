#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpIntv(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return p1[0] - p2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmpIntv);

    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    int mCount = 0;
    merged[mCount] = (int*)malloc(2 * sizeof(int));
    merged[mCount][0] = intervals[0][0];
    merged[mCount][1] = intervals[0][1];
    mCount++;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= merged[mCount - 1][1]) {
            merged[mCount - 1][1] = MAX(merged[mCount - 1][1], intervals[i][1]);
        } else {
            merged[mCount] = (int*)malloc(2 * sizeof(int));
            merged[mCount][0] = intervals[i][0];
            merged[mCount][1] = intervals[i][1];
            mCount++;
        }
    }

    *returnSize = mCount;
    *returnColumnSizes = (int*)malloc(mCount * sizeof(int));
    for (int i = 0; i < mCount; i++) (*returnColumnSizes)[i] = 2;

    return merged;
}