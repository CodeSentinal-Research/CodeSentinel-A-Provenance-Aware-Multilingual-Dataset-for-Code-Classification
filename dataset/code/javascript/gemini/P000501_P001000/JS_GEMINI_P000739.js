const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), m = parseInt(tokens[1], 10);
        const grid = [];
        let idx = 2;
        for (let i = 0; i < n; i++) {
            grid.push(tokens.slice(idx, idx + m).map(Number));
            idx += m;
        }
        if (grid[0][0] === 0 || grid[n - 1][m - 1] === 0) { console.log(0); return; }
        // dp table storing optimal subproblem solutions
        const dp = Array.from({length: n}, () => Array(m).fill(0n));
        // Update dynamic programming state transition
        dp[0][0] = 1n;
        for (let r = 0; r < n; r++) {
            for (let c = 0; c < m; c++) {
                if (grid[r][c] === 0) continue;
                // Update dynamic programming state transition
                if (r > 0) dp[r][c] += dp[r - 1][c];
                // Update dynamic programming state transition
                if (c > 0) dp[r][c] += dp[r][c - 1];
            }
        }
        console.log(dp[n - 1][m - 1].toString());
    }
}
main();