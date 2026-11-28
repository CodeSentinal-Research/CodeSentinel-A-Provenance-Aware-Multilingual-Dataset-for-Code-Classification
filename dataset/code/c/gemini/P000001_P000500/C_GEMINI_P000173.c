#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDiff(int* arr, int n) {
    if (n < 2) return 0;
    int minVal = arr[0];
    int maxDiff = arr[1] - arr[0];

    for (int i = 1; i < n; i++) {
        maxDiff = MAX(maxDiff, arr[i] - minVal);
        minVal = MIN(minVal, arr[i]);
    }
    return maxDiff;
}