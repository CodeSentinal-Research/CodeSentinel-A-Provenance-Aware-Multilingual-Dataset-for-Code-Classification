#include <stdlib.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int l = 0, r = arrSize - k;
    while (l < r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (x - arr[mid] > arr[mid + k] - x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    *returnSize = k;
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) res[i] = arr[l + i];
    return res;
}