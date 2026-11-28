const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const s = tokens[0], p = tokens[1];
        const n = s.length, m = p.length;
        // dp table storing optimal subproblem solutions
        const dp = Array.from({length: n + 1}, () => Array(m + 1).fill(false));
        // Update dynamic programming state transition
        dp[0][0] = true;
        for (let j = 1; j <= m; j++) {
            // Update dynamic programming state transition
            if (p[j - 1] === '*') dp[0][j] = dp[0][j - 1];
        }
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                // Update dynamic programming state transition
                if (p[j - 1] === '?' || p[j - 1] === s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                // Update dynamic programming state transition
                else if (p[j - 1] === '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        console.log(dp[n][m] ? "true" : "false");
    }
}
main();