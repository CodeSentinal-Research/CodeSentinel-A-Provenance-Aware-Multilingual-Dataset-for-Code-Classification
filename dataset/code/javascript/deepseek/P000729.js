function solveSudoku(board) {
    const rowSet = new Set();
    const colSet = new Set();
    const boxSet = new Set();
    const empty = '.'
    const nums = ['1','2','3','4','5','6','7','8','9']

    const isValid = (row, col, num) => {
        // Check if the number exists in the row or column
        return !rowSet.has(num) && !colSet.has(num) && !boxSet.has(num)
    }

    const addNumToSet = (row, col, num) => {
        // Add number to the sets
        rowSet.add(num);
        colSet.add(num);
        boxSet.add(num);
    }

    const removeNumFromSet = (row, col, num) => {
        // Remove number from the sets
        rowSet.delete(num);
        colSet.delete(num);
        boxSet.delete(num);
    }

    const solve = (row = 0, col = 0) => {
        if (row === 9) {
            return true;
        }

        let nextRow, nextCol;

        if (col === 9) {
            nextRow = row + 1;
            nextCol = 0;
        } else {
            nextRow = row;
            nextCol = col + 1;
        }

        if (board[row][col] === empty) {
            for (let num of nums) {
                if (isValid(row, col, num)) {
                    board[row][col] = num;
                    addNumToSet(row, col, num);

                    if (solve(nextRow, nextCol)) {
                        return true;
                    }

                    board[row][col] = empty;
                    removeNumFromSet(row, col, num);
                }
            }

            return false;
        } else {
            return solve(nextRow, nextCol);
        }
    }

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] === empty) {
                for (let num of nums) {
                    if (isValid(i, j, num)) {
                        board[i][j] = num;
                        addNumToSet(i, j, num);

                        if (solve(i, j)) {
                            return board;
                        }

                        board[i][j] = empty;
                        removeNumFromSet(i, j, num);
                    }
                }

                return false;
            }
        }
    }

    return true;
}