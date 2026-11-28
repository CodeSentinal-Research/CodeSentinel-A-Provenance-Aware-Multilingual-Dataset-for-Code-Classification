// P001404 - Equal Row and Column Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const grid = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) {
            row.push(parseInt(input[ptr++], 10));
        }
        grid.push(row);
    }
    const rowCounts = new Map();
    for (let i = 0; i < n; i++) {
        const key = grid[i].join(",");
        rowCounts.set(key, (rowCounts.get(key) || 0) + 1);
    }
    let count = 0;
    for (let j = 0; j < n; j++) {
        const col = [];
        for (let i = 0; i < n; i++) {
            col.push(grid[i][j]);
        }
        const key = col.join(",");
        count += rowCounts.get(key) || 0;
    }
    console.log(count);
}

main();
