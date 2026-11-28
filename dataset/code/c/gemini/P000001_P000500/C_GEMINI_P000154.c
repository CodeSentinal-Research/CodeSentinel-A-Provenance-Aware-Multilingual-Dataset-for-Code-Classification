#include <stdlib.h>
#include <math.h>

int* findTwoElement(int* arr, int n, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    int repeating = -1, missing = -1;

    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);
        if (arr[val - 1] < 0) {
            repeating = val;
        } else {
            arr[val - 1] = -arr[val - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    res[0] = repeating;
    res[1] = missing;
    return res;
}