Sure, here is the JavaScript code to solve Sudoku using backtracking:

function isValid(board, row, col, num) {
    // Check in this row on left side
    for (let i = 0; i < 9; i++)
        if (board[row][i] === num)
            return false;
 
    // Check in this column on top side
    for (let i = 0; i < 9; i++)
        if (board[i][col] === num)
            return false;
 
    // Check the 3x3 box that make a square
    let sqlStartRow = Math.floor(row / 3) * 3;
    let sqlStartCol = Math.floor(col / 3) * 3;
    for (let i = 0; i < 3; i++)
        for (let j = 0; j < 3; j++)
            if (board[sqlStartRow + i][sqlStartCol + j] === num)
                return false;
 
    return true;
}

function solveSudoku(board) {
    for (let row = 0; row < 9; row++)
        for (let col = 0; col < 9; col++)
            if (board[row][col] === 0) {
                for (let num = 1; num <= 9; num++)
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        else
                            board[row][col] = 0;  // unassigned cell
                    }
                return false;  // Sudoku not possible
            }
    return true;
}
This JavaScript code defines two functions: `isValid` and `solveSudoku`. `isValid` checks if a given number can be placed at a specific position in the Sudoku board. `solveSudoku` uses backtracking to solve the Sudoku board. It uses recursive function calls to solve the board. If no number can be placed at a particular cell, it backtracks to previous states. If no valid number can be found, it returns false.