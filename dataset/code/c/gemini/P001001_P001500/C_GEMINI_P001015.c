#include <stdlib.h>

typedef struct {
    int val;
    int count;
} Pair;

int cmpPairs(const void* a, const void* b) {
    return ((Pair*)b)->count - ((Pair*)a)->count;
}

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    qsort(nums, numsSize, sizeof(int), cmpInt);
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));
    int pSize = 0;
    int i = 0;
    while (i < numsSize) {
        int val = nums[i];
        int cnt = 0;
        while (i < numsSize && nums[i] == val) {
            cnt++;
            i++;
        }
        pairs[pSize].val = val;
        pairs[pSize].count = cnt;
        pSize++;
    }
    qsort(pairs, pSize, sizeof(Pair), cmpPairs);
    int* res = (int*)malloc(k * sizeof(int));
    for (int j = 0; j < k; j++) res[j] = pairs[j].val;
    free(pairs);
    return res;
}