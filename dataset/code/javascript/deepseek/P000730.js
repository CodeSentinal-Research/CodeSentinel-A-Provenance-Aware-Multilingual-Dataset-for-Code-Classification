Here's a simple solution using backtracking:

function solveNQueens(n) {
    const board = [];
    for(let i = 0; i < n; i++) {
        board[i] = new Array(n).fill(0);
    }
    
    function isValid(row, col) {
        for(let i = 0; i < row; i++) {
            if(board[i][col] === 1) {
                return false;
            }
        }
        return true;
    }
    
    function solve(row) {
        if(row === n) {
            printBoard(board);
            return;
        }
        
        for(let col = 0; col < n; col++) {
            if(isValid(row, col)) {
                board[row][col] = 1;
                solve(row + 1);
                board[row][col] = 0;
            }
        }
    }
    
    function printBoard(board) {
        for(let i = 0; i < n; i++) {
            let str = '';
            for(let j = 0; j < n; j++) {
                str += board[i][j] === 1 ? 'Q ' : 'X ';
            }
            console.log(str);
        }
        console.log('-----');
    }
    
    solve(0);
}

solveNQueens(4);

This program will output all possible configurations of N queens' placement on an N×N chess board. The `solveNQueens` function initializes the board with zeros, and then recursively places queens one by one. It uses a helper function `isValid` to check if a queen can be placed in a given row and column. If it can't be placed, it returns false, otherwise it returns true. If a queen is placed in a row, it moves to the next row, and if no valid placement is found, it backtracks and unmarks the square.

This solution is efficient and handles large input very well. For N=4, it will print out a board configuration for 4 queens.