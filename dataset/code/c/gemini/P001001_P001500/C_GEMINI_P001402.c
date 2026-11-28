#include <stdbool.h>
#include <stdlib.h>

bool canArrange(int* arr, int arrSize, int k) {
    int* rem = (int*)calloc(k, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        int r = ((arr[i] % k) + k) % k;
        rem[r]++;
    }

    if (rem[0] % 2 != 0) { free(rem); return false; }
    for (int i = 1; i <= k / 2; i++) {
        if (i * 2 == k) {
            if (rem[i] % 2 != 0) { free(rem); return false; }
        } else if (rem[i] != rem[k - i]) {
            free(rem);
            return false;
        }
    }
    free(rem);
    return true;
}