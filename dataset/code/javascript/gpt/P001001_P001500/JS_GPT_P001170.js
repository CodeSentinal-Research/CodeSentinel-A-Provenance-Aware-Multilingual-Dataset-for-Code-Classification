// P001170 - Cherry Pickup
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const grid = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) row.push(parseInt(input[ptr++], 10));
        grid.push(row);
    }
    let dp = Array.from({ length: n }, () => new Array(n).fill(-Infinity));
    dp[0][0] = grid[0][0];
    for (let t = 1; t <= 2 * n - 2; t++) {
        const nextDp = Array.from({ length: n }, () => new Array(n).fill(-Infinity));
        for (let i = Math.max(0, t - (n - 1)); i <= Math.min(n - 1, t); i++) {
            for (let j = Math.max(0, t - (n - 1)); j <= Math.min(n - 1, t); j++) {
                if (grid[i][t - i] === -1 || grid[j][t - j] === -1) continue;
                let val = grid[i][t - i];
                if (i !== j) val += grid[j][t - j];
                for (const pi of [i - 1, i]) {
                    for (const pj of [j - 1, j]) {
                        if (pi >= 0 && pj >= 0) {
                            nextDp[i][j] = Math.max(nextDp[i][j], dp[pi][pj] + val);
                        }
                    }
                }
            }
        }
        dp = nextDp;
    }
    console.log(Math.max(0, dp[n - 1][n - 1]));
}

main();
