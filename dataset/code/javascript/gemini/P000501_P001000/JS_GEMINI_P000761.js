const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const s = tokens[0], t = tokens[1];
        const n = s.length, m = t.length;
        // dp[i] stores optimal answer for prefix of length i
        const dp = Array.from({length: n + 1}, () => Array(m + 1).fill(0n));
        for (let i = 0; i <= n; i++) dp[i][0] = 1n;
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= m; j++) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j];
                // Update dynamic programming state transition
                if (s[i - 1] === t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        console.log(dp[n][m].toString());
    }
}
main();