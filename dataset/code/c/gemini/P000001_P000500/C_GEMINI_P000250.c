#include <stdlib.h>

int determinantOfMatrix(int** matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    int det = 0;
    for (int p = 0; p < n; p++) {
        int** sub = (int**)malloc((n - 1) * sizeof(int*));
        for (int i = 0; i < n - 1; i++) sub[i] = (int*)malloc((n - 1) * sizeof(int));

        for (int i = 1; i < n; i++) {
            int colIdx = 0;
            for (int j = 0; j < n; j++) {
                if (j != p) {
                    sub[i - 1][colIdx++] = matrix[i][j];
                }
            }
        }

        int sign = (p % 2 == 0 ? 1 : -1);
        det += sign * matrix[0][p] * determinantOfMatrix(sub, n - 1);

        for (int i = 0; i < n - 1; i++) free(sub[i]);
        free(sub);
    }
    return det;
}