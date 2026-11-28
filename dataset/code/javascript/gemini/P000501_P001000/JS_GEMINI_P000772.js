const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const e = parseInt(tokens[0], 10), f = parseInt(tokens[1], 10);
        // dp table storing optimal subproblem solutions
        const dp = Array.from({length: e + 1}, () => Array(f + 1).fill(0));
        for (let i = 1; i <= e; i++) { dp[i][1] = 1; dp[i][0] = 0; }
        for (let j = 1; j <= f; j++) dp[1][j] = j;
        for (let i = 2; i <= e; i++) {
            for (let j = 2; j <= f; j++) {
                let minRes = Infinity;
                for (let x = 1; x <= j; x++) {
                    // Update dynamic programming state transition
                    const res = 1 + Math.max(dp[i - 1][x - 1], dp[i][j - x]);
                    if (res < minRes) minRes = res;
                }
                // Update dynamic programming state transition
                dp[i][j] = minRes;
            }
        }
        console.log(dp[e][f]);
    }
}
main();