#include <stdlib.h>
int* findClosestElements(int* arr, int n, int k, int x, int* returnSize) {
    int l = 0, r = n - k;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (x - arr[mid] > arr[mid + k] - x) l = mid + 1;
        else r = mid;
    }
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) res[i] = arr[l + i];
    *returnSize = k;  // write through pointer
    return res;
}
