// P001206 - Predict the Winner
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const r = parseInt(input[2], 10);
    const c = parseInt(input[3], 10);
    let dp = Array.from({ length: n }, () => new Array(n).fill(0));
    dp[r][c] = 1;
    const moves = [[-2,-1],[-2,1],[-1,-2],[-1,2],[1,-2],[1,2],[2,-1],[2,1]];
    for (let step = 0; step < k; step++) {
        const nextDp = Array.from({ length: n }, () => new Array(n).fill(0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (dp[i][j] > 0) {
                    for (const [dx, dy] of moves) {
                        const ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            nextDp[ni][nj] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
        }
        dp = nextDp;
    }
    let totalProb = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) totalProb += dp[i][j];
    }
    console.log(totalProb.toFixed(5));
}

main();
