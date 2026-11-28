const fs = require('fs');
function isValid(board, r, c, ch) {
    for (let i = 0; i < 9; i++) {
        if (board[r][i] === ch || board[i][c] === ch) return false;
        if (board[3 * Math.floor(r / 3) + Math.floor(i / 3)][3 * Math.floor(c / 3) + (i % 3)] === ch) return false;
    }
    return true;
}
// Solves 'Sudoku Solver' by applying optimal Recursion logic.
function solve(board) {
    for (let r = 0; r < 9; r++) {
        for (let c = 0; c < 9; c++) {
            if (board[r][c] === '.') {
                for (let d = 1; d <= 9; d++) {
                    const ch = String(d);
                    if (isValid(board, r, c, ch)) {
                        board[r][c] = ch;
                        if (solve(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 9 && tokens[0] !== '') {
        const board = tokens.slice(0, 9).map(row => row.split(''));
        solve(board);
        for (const row of board) console.log(row.join(''));
    }
}
main();