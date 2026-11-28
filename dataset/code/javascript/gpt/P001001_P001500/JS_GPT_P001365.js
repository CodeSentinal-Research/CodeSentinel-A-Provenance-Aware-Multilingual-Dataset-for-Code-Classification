// P001365 - Gold Mine Path
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const grid = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        grid.push(row);
    }
    let maxGold = 0;
    function dfs(i, j) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] === 0) return 0;
        const val = grid[i][j];
        grid[i][j] = 0;
        const total = val + Math.max(
            dfs(i + 1, j), dfs(i - 1, j),
            dfs(i, j + 1), dfs(i, j - 1)
        );
        grid[i][j] = val;
        return total;
    }
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] > 0) {
                maxGold = Math.max(maxGold, dfs(i, j));
            }
        }
    }
    console.log(maxGold);
}

main();
