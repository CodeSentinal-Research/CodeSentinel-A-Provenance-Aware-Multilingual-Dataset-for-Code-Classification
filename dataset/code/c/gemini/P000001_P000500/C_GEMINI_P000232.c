#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int countSmallerC(int* row, int len, int target) {
    int l = 0, r = len;
    while (l < r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (row[mid] <= target) l = mid + 1;
        else r = mid;
    }
    return l;
}

int median(int** matrix, int R, int C) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < R; i++) {
        min = MIN(min, matrix[i][0]);
        max = MAX(max, matrix[i][C - 1]);
    }

    int desired = (R * C + 1) / 2;
    while (min < max) {
        // Calculate midpoint to prevent potential overflow
        int mid = min + (max - min) / 2;
        int count = 0;
        for (int i = 0; i < R; i++) {
            count += countSmallerC(matrix[i], C, mid);
        }
        if (count < desired) min = mid + 1;
        else max = mid;
    }
    return min;
}