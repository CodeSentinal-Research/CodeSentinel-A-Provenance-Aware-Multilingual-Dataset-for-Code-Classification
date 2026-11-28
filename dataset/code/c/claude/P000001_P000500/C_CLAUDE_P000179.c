#include <stdlib.h>
#include <string.h>
static int* rel_order;
static int rel_max;
int cmpRel(const void* a, const void* b) {
    int va = *(int*)a, vb = *(int*)b;
    int oa = (va < rel_max) ? rel_order[va] : -1;
    int ob = (vb < rel_max) ? rel_order[vb] : -1;
    if (oa >= 0 && ob >= 0) return oa - ob;
    if (oa >= 0) return -1;
    if (ob >= 0) return 1;
    return va - vb;
}
int* relativeSortArray(int* arr1, int n1, int* arr2, int n2, int* returnSize) {
    rel_max = 1001;
    rel_order = (int*)malloc(rel_max * sizeof(int));
    for (int i = 0; i < rel_max; i++) rel_order[i] = -1;
    for (int i = 0; i < n2; i++) rel_order[arr2[i]] = i;
    int* res = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) res[i] = arr1[i];
    qsort(res, n1, sizeof(int), cmpRel);
    free(rel_order);
    *returnSize = n1;  // write through pointer
    return res;
}
