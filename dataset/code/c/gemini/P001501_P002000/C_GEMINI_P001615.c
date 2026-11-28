int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize, n = matrixColSize[0];
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    for (int c1 = 0; c1 < n; c1++) {
        for (int c2 = c1; c2 < n; c2++) {
            for (int r1 = 0; r1 < m; r1++) {
                int sum = 0;
                for (int r2 = r1; r2 < m; r2++) {
                    sum += matrix[r2][c2] - (c1 > 0 ? matrix[r2][c1 - 1] : 0);
                    if (sum == target) ans++;
                }
            }
        }
    }
    return ans;
}