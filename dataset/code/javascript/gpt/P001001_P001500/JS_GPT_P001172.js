// P001172 - Unique Paths with Obstacles
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
    if (grid[0][0] === 1) { console.log(0); return; }
    const dp = new Array(c).fill(0n);
    dp[0] = 1n;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] === 1) {
                dp[j] = 0n;
            } else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    console.log(dp[c - 1].toString());
}

main();
