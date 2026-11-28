#include <stdlib.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    *returnSize = k;
    int left = 0, right = arrSize - k;
    // Binary search loop to narrow down range
    while (left < right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[left + i];
    }
    return result;
}