#include <stdlib.h>

long long mergeC(long long* arr, long long* temp, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    long long inv = 0;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (i = l; i <= r; i++) arr[i] = temp[i];
    return inv;
}

// Sorts the input array into ordered sequence.
long long mergeSortC(long long* arr, long long* temp, int l, int r) {
    long long inv = 0;
    if (l < r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        inv += mergeSortC(arr, temp, l, mid);
        inv += mergeSortC(arr, temp, mid + 1, r);
        inv += mergeC(arr, temp, l, mid, r);
    }
    return inv;
}

long long inversionCount(long long* arr, long long N) {
    long long* temp = (long long*)malloc(N * sizeof(long long));
    long long ans = mergeSortC(arr, temp, 0, N - 1);
    free(temp);
    return ans;
}