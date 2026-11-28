#include <stdbool.h>
void setZeroes(int** matrix, int m, int n) {
    bool* rows = (bool*)calloc(m, sizeof(bool));
    bool* cols = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0) { rows[i] = true; cols[j] = true; }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (rows[i] || cols[j]) matrix[i][j] = 0;
    free(rows); free(cols);
}
