const fs = require('fs');
// Solves 'N-Queens' by applying optimal Recursion logic.
function solveNQueens(n) {
    const board = Array.from({length: n}, () => Array(n).fill('.'));
    const cols = new Set(), d1 = new Set(), d2 = new Set();
    function backtrack(r) {
        if (r === n) {
            for (const row of board) console.log(row.join(''));
            console.log();
            return;
        }
        for (let c = 0; c < n; c++) {
            if (cols.has(c) || d1.has(r + c) || d2.has(r - c)) continue;
            cols.add(c); d1.add(r + c); d2.add(r - c);
            board[r][c] = 'Q';
            backtrack(r + 1);
            board[r][c] = '.';
            cols.delete(c); d1.delete(r + c); d2.delete(r - c);
        }
    }
    backtrack(0);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        solveNQueens(parseInt(tokens[0], 10));
    }
}
main();