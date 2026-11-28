#include <stdbool.h>

bool areIdentical(int** mat1, int** mat2, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat1[i][j] != mat2[i][j]) return false;
        }
    }
    return true;
}