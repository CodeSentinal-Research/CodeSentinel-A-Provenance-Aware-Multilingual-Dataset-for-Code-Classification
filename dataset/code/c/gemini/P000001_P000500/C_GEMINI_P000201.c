#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSumIS(int* arr, int n) {
    int* msis = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) msis[i] = arr[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i];
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) max = MAX(max, msis[i]);
    free(msis);
    return max;
}