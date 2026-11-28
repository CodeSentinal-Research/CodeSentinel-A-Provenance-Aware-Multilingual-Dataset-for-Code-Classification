// Solves 'N-Queens' by applying optimal Backtracking logic.
function solveNQueens(n) {
    const cols = new Set();
    const posDiag = new Set();
    const negDiag = new Set();
    const res = [];
    const board = Array.from({ length: n }, () => new Array(n).fill('.'));

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(r) {
        if (r === n) {
            res.push(board.map(row => row.join('')));
            return;
        }

        for (let c = 0; c < n; c++) {
            if (cols.has(c) || posDiag.has(r + c) || negDiag.has(r - c)) continue;
            cols.add(c);
            posDiag.add(r + c);
            negDiag.add(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1);

            cols.delete(c);
            posDiag.delete(r + c);
            negDiag.delete(r - c);
            board[r][c] = '.';
        }
    }

    backtrack(0);
    return res;
}

module.exports = { solveNQueens };