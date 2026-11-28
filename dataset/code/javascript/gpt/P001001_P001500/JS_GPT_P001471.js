// P001471 - Container With Most Water
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
    const dp = Array.from({ length: r }, () => new Array(c).fill(0));
    dp[0][0] = grid[0][0];
    for (let j = 1; j < c; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (let i = 1; i < r; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (let i = 1; i < r; i++) {
        for (let j = 1; j < c; j++) {
            dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    console.log(dp[r - 1][c - 1]);
}

main();
