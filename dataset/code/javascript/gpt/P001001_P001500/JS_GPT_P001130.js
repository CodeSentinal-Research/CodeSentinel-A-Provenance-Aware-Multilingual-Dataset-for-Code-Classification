// P001130 - Regions Cut by Slashes
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length === 0) return;
    const n = parseInt(lines[0].trim(), 10);
    const grid = [];
    for (let i = 1; i <= n; i++) {
        grid.push(lines[i]);
    }
    const size = n * 3;
    const g = Array.from({ length: size }, () => new Array(size).fill(0));
    for (let i = 0; i < n; i++) {
        const row = grid[i] || "";
        for (let j = 0; j < n; j++) {
            const ch = row[j];
            if (ch === "/") {
                g[i * 3][j * 3 + 2] = 1;
                g[i * 3 + 1][j * 3 + 1] = 1;
                g[i * 3 + 2][j * 3] = 1;
            } else if (ch === "\\") {
                g[i * 3][j * 3] = 1;
                g[i * 3 + 1][j * 3 + 1] = 1;
                g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }
    function dfs(x, y) {
        if (x < 0 || x >= size || y < 0 || y >= size || g[x][y] === 1) return;
        g[x][y] = 1;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
    let regions = 0;
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            if (g[i][j] === 0) {
                regions++;
                dfs(i, j);
            }
        }
    }
    console.log(regions);
}

main();
