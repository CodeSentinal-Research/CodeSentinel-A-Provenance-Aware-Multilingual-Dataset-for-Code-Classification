// P001311 - N-Queens
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const cols = new Set(), diag1 = new Set(), diag2 = new Set();
    const board = Array.from({ length: n }, () => new Array(n).fill("."));
    const results = [];
    function solve(row) {
        if (row === n) {
            results.push(board.map(r => r.join("")));
            return;
        }
        for (let c = 0; c < n; c++) {
            const d1 = row - c, d2 = row + c;
            if (!cols.has(c) && !diag1.has(d1) && !diag2.has(d2)) {
                cols.add(c); diag1.add(d1); diag2.add(d2);
                board[row][c] = "Q";
                solve(row + 1);
                board[row][c] = ".";
                cols.delete(c); diag1.delete(d1); diag2.delete(d2);
            }
        }
    }
    solve(0);
    for (const sol of results) {
        for (const row of sol) console.log(row);
        console.log("");
    }
}

main();
