#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Sorts the input array into ordered sequence.
int maxChunksToSorted(int* arr, int arrSize) {
    int* minRight = (int*)malloc(arrSize * sizeof(int));
    minRight[arrSize - 1] = arr[arrSize - 1];

    for (int i = arrSize - 2; i >= 0; i--) {
        minRight[i] = MIN(arr[i], minRight[i + 1]);
    }

    int maxLeft = 0, chunks = 1;
    for (int i = 0; i < arrSize - 1; i++) {
        maxLeft = MAX(maxLeft, arr[i]);
        if (maxLeft <= minRight[i + 1]) chunks++;
    }
    free(minRight);
    return chunks;
}