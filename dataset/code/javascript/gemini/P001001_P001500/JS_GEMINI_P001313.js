// Solves 'Sudoku Solver' by applying optimal Backtracking logic.
function solveSudoku(board) {
    // Helper function to evaluate isvalid for problem constraints.
    function isValid(r, c, ch) {
        for (let i = 0; i < 9; i++) {
            if (board[r][i] === ch || board[i][c] === ch) return false;
            if (board[3 * Math.floor(r / 3) + Math.floor(i / 3)][3 * Math.floor(c / 3) + (i % 3)] === ch) return false;
        }
        return true;
    }

    // Solves 'Sudoku Solver' by applying optimal Backtracking logic.
    function solve() {
        for (let r = 0; r < 9; r++) {
            for (let c = 0; c < 9; c++) {
                if (board[r][c] === '.') {
                    for (let d = 1; d <= 9; d++) {
                        const ch = String(d);
                        if (isValid(r, c, ch)) {
                            board[r][c] = ch;
                            if (solve()) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    solve();
}

module.exports = { solveSudoku };