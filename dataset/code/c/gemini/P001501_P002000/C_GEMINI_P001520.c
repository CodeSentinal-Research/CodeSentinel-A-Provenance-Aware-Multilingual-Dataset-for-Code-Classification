#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Sorts the input array into ordered sequence.
int maxChunksToSorted(int* arr, int arrSize) {
    int maxSeen = 0, chunks = 0;
    for (int i = 0; i < arrSize; i++) {
        maxSeen = MAX(maxSeen, arr[i]);
        if (maxSeen == i) chunks++;
    }
    return chunks;
}