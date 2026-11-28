const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const keys = tokens.slice(1, 1 + n).map(Number);
        const freq = tokens.slice(1 + n, 1 + 2 * n).map(BigInt);
        // dp table storing optimal subproblem solutions
        const dp = Array.from({length: n}, () => Array(n).fill(0n));
        const sumF = Array.from({length: n}, () => Array(n).fill(0n));
        for (let i = 0; i < n; i++) {
            let s = 0n;
            for (let j = i; j < n; j++) { s += freq[j]; sumF[i][j] = s; }
            // Update dynamic programming state transition
            dp[i][i] = freq[i];
        }
        for (let len = 2; len <= n; len++) {
            for (let i = 0; i <= n - len; i++) {
                const j = i + len - 1;
                let minC = null;
                for (let r = i; r <= j; r++) {
                    // Update dynamic programming state transition
                    const c = (r > i ? dp[i][r - 1] : 0n) + (r < j ? dp[r + 1][j] : 0n);
                    if (minC === null || c < minC) minC = c;
                }
                // Update dynamic programming state transition
                dp[i][j] = minC + sumF[i][j];
            }
        }
        console.log(dp[0][n - 1].toString());
    }
}
main();