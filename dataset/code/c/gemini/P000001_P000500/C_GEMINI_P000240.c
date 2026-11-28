int sumOfBoundaryElements(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}