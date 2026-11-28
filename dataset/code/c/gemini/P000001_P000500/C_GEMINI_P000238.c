#include <stdbool.h>

// Sorts the input array into ordered sequence.
bool isOrthogonal(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dot = 0;
            for (int k = 0; k < n; k++) {
                dot += matrix[i][k] * matrix[j][k];
            }
            if (i == j && dot != 1) return false;
            if (i != j && dot != 0) return false;
        }
    }
    return true;
}