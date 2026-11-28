const fs = require('fs');
function main() {
    const token = fs.readFileSync(0, 'utf-8').trim();
    if (token) {
        const target = parseInt(token, 10);
        // dp table storing optimal subproblem solutions
        const dp = new Array(target + 1).fill(0);
        for (let t = 1; t <= target; t++) {
            let k = 0;
            while ((1 << k) <= t) k++;
            if (t === (1 << k) - 1) {
                // Update dynamic programming state transition
                dp[t] = k;
                continue;
            }
            // Update dynamic programming state transition
            dp[t] = dp[(1 << k) - 1 - t] + k + 1;
            for (let j = 0; j < k - 1; j++) {
                // Update dynamic programming state transition
                dp[t] = Math.min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        console.log(dp[target]);
    }
}
main();