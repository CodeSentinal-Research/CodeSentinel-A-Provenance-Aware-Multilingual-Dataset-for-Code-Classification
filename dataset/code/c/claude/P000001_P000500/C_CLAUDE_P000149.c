int rowWithMax1s(int** matrix, int m, int n) {
    int maxRow = -1, maxCount = -1;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) cnt += matrix[i][j];
        if (cnt > maxCount) { maxCount = cnt; maxRow = i; }
    }
    return maxRow;
}
