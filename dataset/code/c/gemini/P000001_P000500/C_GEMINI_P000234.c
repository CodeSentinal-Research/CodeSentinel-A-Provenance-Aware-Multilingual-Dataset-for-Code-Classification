void booleanMatrix(int R, int C, int** matrix) {
    int rowFlag[1005] = {0};
    int colFlag[1005] = {0};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 1) {
                rowFlag[i] = 1;
                colFlag[j] = 1;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (rowFlag[i] == 1 || colFlag[j] == 1) {
                matrix[i][j] = 1;
            }
        }
    }
}