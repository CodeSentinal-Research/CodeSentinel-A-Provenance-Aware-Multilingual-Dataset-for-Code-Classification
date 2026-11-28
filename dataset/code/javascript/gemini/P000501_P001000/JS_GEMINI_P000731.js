const fs = require('fs');
function totalNQueens(n) {
    const cols = new Set(), d1 = new Set(), d2 = new Set();
    let count = 0;
    function backtrack(r) {
        if (r === n) { count++; return; }
        for (let c = 0; c < n; c++) {
            if (cols.has(c) || d1.has(r + c) || d2.has(r - c)) continue;
            cols.add(c); d1.add(r + c); d2.add(r - c);
            backtrack(r + 1);
            cols.delete(c); d1.delete(r + c); d2.delete(r - c);
        }
    }
    backtrack(0);
    return count;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(totalNQueens(parseInt(tokens[0], 10)));
    }
}
main();