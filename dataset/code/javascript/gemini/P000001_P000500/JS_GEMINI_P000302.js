const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const dict = new Set(tokens.slice(1));
        const n = s.length;
        // dp table storing optimal subproblem solutions
        const dp = new Array(n + 1).fill(false);
        // Update dynamic programming state transition
        dp[0] = true;
        for (let i = 1; i <= n; i++) {
            for (let j = 0; j < i; j++) {
                if (dp[j] && dict.has(s.substring(j, i))) {
                    // Update dynamic programming state transition
                    dp[i] = true;
                    break;
                }
            }
        }
        console.log(dp[n] ? "Yes" : "No");
    }
}

main();