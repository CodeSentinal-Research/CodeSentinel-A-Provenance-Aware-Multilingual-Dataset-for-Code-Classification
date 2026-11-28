#include <stdlib.h>

typedef struct {
    int val, idx;
} Pair;

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int cmpPair(const void* a, const void* b) {
    return ((Pair*)b)->val - ((Pair*)a)->val;
}

int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmpInt);
    Pair* p2 = (Pair*)malloc(nums2Size * sizeof(Pair));
    for (int i = 0; i < nums2Size; i++) {
        p2[i].val = nums2[i];
        p2[i].idx = i;
    }
    qsort(p2, nums2Size, sizeof(Pair), cmpPair);

    int* res = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    int l = 0, r = nums1Size - 1;
    for (int i = 0; i < nums2Size; i++) {
        if (nums1[r] > p2[i].val) {
            res[p2[i].idx] = nums1[r--];
        } else {
            res[p2[i].idx] = nums1[l++];
        }
    }
    free(p2);
    return res;
}