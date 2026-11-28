const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const dims = tokens.slice(1, 1 + n).map(BigInt);
        // dp table storing optimal subproblem solutions
        const dp = Array.from({length: n}, () => Array(n).fill(0n));
        for (let len = 2; len < n; len++) {
            for (let i = 1; i < n - len + 1; i++) {
                const j = i + len - 1;
                let minCost = null;
                for (let k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    const cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                    if (minCost === null || cost < minCost) minCost = cost;
                }
                // Update dynamic programming state transition
                dp[i][j] = minCost;
            }
        }
        console.log(dp[1][n - 1].toString());
    }
}
main();