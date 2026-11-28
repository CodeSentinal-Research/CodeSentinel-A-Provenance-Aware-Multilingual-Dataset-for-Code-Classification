#include <stdbool.h>
#include <stdlib.h>
int cmpInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }
bool containsDuplicate(int* nums, int n) {
    int* tmp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) tmp[i] = nums[i];
    qsort(tmp, n, sizeof(int), cmpInt);
    bool found = false;
    for (int i = 0; i < n - 1; i++) if (tmp[i] == tmp[i+1]) { found = true; break; }
    free(tmp);
    return found;
}
