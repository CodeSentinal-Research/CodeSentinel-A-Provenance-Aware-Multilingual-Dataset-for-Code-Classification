#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpPlat(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findPlatform(int* arr, int* dep, int n) {
    qsort(arr, n, sizeof(int), cmpPlat);
    qsort(dep, n, sizeof(int), cmpPlat);

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            maxPlatforms = MAX(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}