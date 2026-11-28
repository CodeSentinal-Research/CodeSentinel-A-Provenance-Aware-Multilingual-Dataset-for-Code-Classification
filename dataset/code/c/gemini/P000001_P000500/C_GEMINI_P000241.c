#include <stdbool.h>

int findSaddlePoint(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for (int i = 0; i < n; i++) {
        int minRow = matrix[i][0];
        int colIdx = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < minRow) {
                minRow = matrix[i][j];
                colIdx = j;
            }
        }

        bool isSaddle = true;
        for (int k = 0; k < n; k++) {
            if (matrix[k][colIdx] > minRow) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) return minRow;
    }
    return -1;
}