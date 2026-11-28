void upperTriangular(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            matrix[i][j] = 0;
        }
    }
}