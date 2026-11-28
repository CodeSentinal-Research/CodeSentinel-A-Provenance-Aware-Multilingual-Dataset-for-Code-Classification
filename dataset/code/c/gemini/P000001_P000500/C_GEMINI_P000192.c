#include <stdlib.h>

void segregateElements(int* arr, int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) temp[idx++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) temp[idx++] = arr[i];
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    free(temp);
}