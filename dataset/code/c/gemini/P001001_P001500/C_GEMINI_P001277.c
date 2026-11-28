#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Sorts the input array into ordered sequence.
int maxChunksToSorted(int* arr, int arrSize) {
    int curMax = 0, chunks = 0;
    for (int i = 0; i < arrSize; i++) {
        curMax = MAX(curMax, arr[i]);
        if (curMax == i) chunks++;
    }
    return chunks;
}