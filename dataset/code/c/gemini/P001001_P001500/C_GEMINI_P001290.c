#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumScore(int a, int b, int c) {
    int arr[3] = {a, b, c};
    qsort(arr, 3, sizeof(int), cmpInt);
    if (arr[0] + arr[1] <= arr[2]) {
        return arr[0] + arr[1];
    }
    return (a + b + c) / 2;
}