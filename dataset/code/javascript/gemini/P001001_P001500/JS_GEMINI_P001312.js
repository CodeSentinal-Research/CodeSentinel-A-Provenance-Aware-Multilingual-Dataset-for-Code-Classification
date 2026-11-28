// Helper function to evaluate totalnqueens for problem constraints.
function totalNQueens(n) {
    const cols = new Set();
    const posDiag = new Set();
    const negDiag = new Set();

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(r) {
        if (r === n) return 1;
        let count = 0;
        for (let c = 0; c < n; c++) {
            if (cols.has(c) || posDiag.has(r + c) || negDiag.has(r - c)) continue;
            cols.add(c);
            posDiag.add(r + c);
            negDiag.add(r - c);

            count += backtrack(r + 1);

            cols.delete(c);
            posDiag.delete(r + c);
            negDiag.delete(r - c);
        }
        return count;
    }

    return backtrack(0);
}

module.exports = { totalNQueens };