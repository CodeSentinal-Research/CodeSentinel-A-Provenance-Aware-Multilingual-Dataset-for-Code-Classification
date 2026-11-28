char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    int rows[3] = {0}, cols[3] = {0};
    int diag = 0, antiDiag = 0;

    for (int i = 0; i < movesSize; i++) {
        int r = moves[i][0], c = moves[i][1];
        int val = (i % 2 == 0) ? 1 : -1;

        rows[r] += val;
        cols[c] += val;
        if (r == c) diag += val;
        if (r + c == 2) antiDiag += val;

        if (rows[r] == 3 || cols[c] == 3 || diag == 3 || antiDiag == 3) return "A";
        if (rows[r] == -3 || cols[c] == -3 || diag == -3 || antiDiag == -3) return "B";
    }
    return movesSize == 9 ? "Draw" : "Pending";
}