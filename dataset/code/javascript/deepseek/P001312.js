function nQueens(n) {
    var count = 0;
    var board = new Array(n);
    for (var i = 0; i < n; i++) {
        board[i] = new Array(n).fill(0);
    }

    function helper(row) {
        if (row == n) {
            count++;
            return;
        }

        for (var col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;
                helper(row + 1);
                board[row][col] = 0;
            }
        }
    }

    function isSafe(row, col, board, n) {
        for (var i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }

        var dupCol = col;
        var dupRow = row;

        while (dupRow > 0 && dupCol > 0) {
            if (board[--dupRow][--dupCol] == 1) {
                return false;
            }
        }

        dupCol = col;
        dupRow = row;

        while (dupRow < n - 1 && dupCol < n - 1) {
            if (board[++dupRow][++dupCol] == 1) {
                return false;
            }
        }

        dupCol = col;
        dupRow = row;

        while (dupRow < n - 1 && dupCol > 0) {
            if (board[++dupRow][--dupCol] == 1) {
                return false;
            }
        }

        return true;
    }

    helper(0);
    return count;
}