function totalNQueens(n) {
    let count = 0;
    const col = new Set(), d1 = new Set(), d2 = new Set();
    function solve(row) {
        if (row === n) { count++; return; }
        for (let c = 0; c < n; c++) {
            if (col.has(c) || d1.has(row - c) || d2.has(row + c)) continue;
            col.add(c); d1.add(row - c); d2.add(row + c);
            solve(row + 1);
            col.delete(c); d1.delete(row - c); d2.delete(row + c);
        }
    }
    solve(0);
    return count;
}

module.exports = { totalNQueens };
