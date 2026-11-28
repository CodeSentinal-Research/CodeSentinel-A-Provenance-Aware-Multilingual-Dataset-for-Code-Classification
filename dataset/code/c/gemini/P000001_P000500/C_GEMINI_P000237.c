void rotateMatrixRow(int N, int M, int K, int** Mat) {
    int k = K % M;
    for (int i = 0; i < N; i++) {
        int temp[1005];
        for (int j = 0; j < M; j++) {
            temp[j] = Mat[i][(j + k) % M];
        }
        for (int j = 0; j < M; j++) {
            Mat[i][j] = temp[j];
        }
    }
}