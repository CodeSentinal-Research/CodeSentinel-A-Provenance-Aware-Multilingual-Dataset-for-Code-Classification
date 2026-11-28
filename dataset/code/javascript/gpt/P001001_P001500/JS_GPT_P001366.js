// P001366 - Find Unique Paths III
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const grid = [];
    let startX = 0, startY = 0, empty = 1;
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) {
            const val = parseInt(input[ptr++], 10);
            row.push(val);
            if (val === 1) { startX = i; startY = j; }
            else if (val === 0) { empty++; }
        }
        grid.push(row);
    }
    let paths = 0;
    function dfs(x, y, remain) {
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] < 0) return;
        if (grid[x][y] === 2) {
            if (remain === 0) paths++;
            return;
        }
        const temp = grid[x][y];
        grid[x][y] = -2;
        dfs(x + 1, y, remain - 1);
        dfs(x - 1, y, remain - 1);
        dfs(x, y + 1, remain - 1);
        dfs(x, y - 1, remain - 1);
        grid[x][y] = temp;
    }
    dfs(startX, startY, empty);
    console.log(paths);
}

main();
