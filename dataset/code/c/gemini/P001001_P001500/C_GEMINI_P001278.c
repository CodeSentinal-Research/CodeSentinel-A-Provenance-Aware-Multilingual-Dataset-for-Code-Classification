#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Sorts the input array into ordered sequence.
int maxChunksToSorted(int* arr, int arrSize) {
    int stack[arrSize + 1];
    int top = 0;

    for (int i = 0; i < arrSize; i++) {
        int curMax = arr[i];
        while (top > 0 && stack[top - 1] > arr[i]) {
            curMax = MAX(curMax, stack[--top]);
        }
        stack[top++] = curMax;
    }
    return top;
}