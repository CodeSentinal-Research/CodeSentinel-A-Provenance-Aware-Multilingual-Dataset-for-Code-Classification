function totalNQueens(n) {
    if (n < 1 || n > 14) {
        throw new Error('Invalid input');
    }

    let count = 0;
    const board = [];

    function isValid(row, column) {
        for (let i = 0; i < row; i++) {
            if (board[i][column] === 1) {
                return false;
            }
        }

        for (let i = 0; i < row; i++) {
            if (board[row][i] === 1) {
                return false;
            }
        }

        return true;
    }

    function placeQueen(row, column) {
        if (row === n) {
            count++;
            return;
        }

        for (let i = 0; i < n; i++) {
            if (isValid(row, i)) {
                board[row][i] = 1;
                placeQueen(row + 1, i);
                board[row][i] = 0;
            }
        }
    }

    for (let i = 0; i < n; i++) {
        board[i] = [];
        for (let j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    placeQueen(0, 0);

    return count;
}