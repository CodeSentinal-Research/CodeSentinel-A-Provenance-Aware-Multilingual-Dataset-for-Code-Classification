int rowWithMax1s(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return -1;
    int m = matrixSize, n = matrixColSize[0];
    int r = 0, c = n - 1;
    int maxRow = -1;

    while (r < m && c >= 0) {
        if (matrix[r][c] == 1) {
            maxRow = r;
            c--;
        } else {
            r++;
        }
    }
    return maxRow;
}