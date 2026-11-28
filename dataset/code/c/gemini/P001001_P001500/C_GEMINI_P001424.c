#include <stdbool.h>
#include <stdlib.h>

int cmpIntOcc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool uniqueOccurrences(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmpIntOcc);
    int freqs[1005];
    int fSize = 0;
    int count = 1;

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] == arr[i - 1]) count++;
        else {
            freqs[fSize++] = count;
            count = 1;
        }
    }
    freqs[fSize++] = count;

    qsort(freqs, fSize, sizeof(int), cmpIntOcc);
    for (int i = 1; i < fSize; i++) {
        if (freqs[i] == freqs[i - 1]) return false;
    }
    return true;
}