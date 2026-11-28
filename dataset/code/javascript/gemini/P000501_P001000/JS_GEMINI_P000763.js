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
        for (let j = 2; j <= m; j += 2) {
            // Update dynamic programming state transition
            if (p[j - 1] === '*') dp[0][j] = dp[0][j - 2];
        }
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                if (p[j - 1] === '*') {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] === '.' || p[j - 2] === s[i - 1]) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (p[j - 1] === '.' || p[j - 1] === s[i - 1]) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        console.log(dp[n][m] ? "true" : "false");
    }
}
main();