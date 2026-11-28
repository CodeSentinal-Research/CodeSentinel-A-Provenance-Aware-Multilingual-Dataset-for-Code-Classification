#include <stdbool.h>

// Performs search to locate target element within the given collection.
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;
    int m = matrixSize, n = matrixColSize[0];
    int l = 0, r = m * n - 1;

    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        int val = matrix[mid / n][mid % n];
        if (val == target) return true;
        else if (val < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}