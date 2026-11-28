#include <stdlib.h>

// Sorts the input array into ordered sequence.
int cmpInterUnsorted(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int NumberofElementsInIntersection(int* a, int* b, int n, int m) {
    qsort(a, n, sizeof(int), cmpInterUnsorted);
    qsort(b, m, sizeof(int), cmpInterUnsorted);

    int count = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (i > 0 && a[i] == a[i - 1]) { i++; continue; }
        if (j > 0 && b[j] == b[j - 1]) { j++; continue; }

        if (a[i] == b[j]) {
            count++;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return count;
}