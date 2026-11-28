#include <stdlib.h>
int* spiralOrder(int** matrix, int rows, int cols, int* returnSize) {
    *returnSize = rows * cols;  // write through pointer
    int* res = (int*)malloc(rows * cols * sizeof(int));
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1, idx = 0;
    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; c++) res[idx++] = matrix[top][c]; top++;
        for (int r = top; r <= bottom; r++) res[idx++] = matrix[r][right]; right--;
        if (top <= bottom) { for (int c = right; c >= left; c--) res[idx++] = matrix[bottom][c]; bottom--; }
        if (left <= right) { for (int r = bottom; r >= top; r--) res[idx++] = matrix[r][left]; left++; }
    }
    return res;
}
