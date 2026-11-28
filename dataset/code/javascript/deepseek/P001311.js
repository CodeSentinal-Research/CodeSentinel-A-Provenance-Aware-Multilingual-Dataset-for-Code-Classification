Sure, here is a simple JavaScript code that uses backtracking to solve the N-Queens problem. 

function solve(N) {
    let board = [];
    let count = 0;

    function is_safe(board, row, column) {
        for (let i = 0; i < row; i++) {
            if (board[i][column] === 1) {
                return false;
            }
        }
        return true;
    }

    function solve_n_queens(board, column) {
        if (column >= N) {
            count++;
            print_board(board, N);
            return;
        }

        for (let i = 0; i < N; i++) {
            if (is_safe(board, i, column)) {
                board[i][column] = 1;
                solve_n_queens(board, column + 1);
                board[i][column] = 0;
            }
        }
    }

    function init_board(N) {
        board = [];
        for (let i = 0; i < N; i++) {
            board[i] = [];
            for (let j = 0; j < N; j++) {
                board[i][j] = 0;
            }
        }
    }

    function print_board(board, N) {
        for (let i = 0; i < N; i++) {
            let str = "";
            for (let j = 0; j < N; j++) {
                str += board[i][j] ? "Q " : "X ";
            }
            console.log(str);
        }
        console.log("-------");
    }

    init_board(N);
    solve_n_queens(board, 0);
    console.log("Total solutions: " + count);
}

solve(4);

This code will print all valid configurations and the total number of solutions. The `solve` function takes an integer `N` and uses backtracking to find all possible configurations of `N` queens on a `N x N` chessboard. The `is_safe` function is used to check if a queen can be placed on a given cell or not.