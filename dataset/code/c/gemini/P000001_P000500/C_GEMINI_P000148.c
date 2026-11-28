#include <stdbool.h>

bool isSymmetric(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixSize; j++) {
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}