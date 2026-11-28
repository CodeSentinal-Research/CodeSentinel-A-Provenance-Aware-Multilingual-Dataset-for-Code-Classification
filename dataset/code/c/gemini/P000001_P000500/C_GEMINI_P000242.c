int countZeroes(int** A, int N) {
    int r = 0, c = N - 1;
    int count = 0;

    while (r < N && c >= 0) {
        if (A[r][c] == 0) {
            count += (c + 1);
            r++;
        } else {
            c--;
        }
    }
    return count;
}