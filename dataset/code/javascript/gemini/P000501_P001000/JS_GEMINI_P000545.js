const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        // dp[i] stores optimal answer for prefix of length i
        const dp = new Array(n).fill(0);
        const q = [];
        let maxAns = -Infinity;
        for (let i = 0; i < n; i++) {
            while (q.length > 0 && q[0] < i - k) q.shift();
            // Update dynamic programming state transition
            dp[i] = nums[i] + (q.length > 0 && dp[q[0]] > 0 ? dp[q[0]] : 0);
            // Update dynamic programming state transition
            maxAns = Math.max(maxAns, dp[i]);
            // Update dynamic programming state transition
            while (q.length > 0 && dp[q[q.length - 1]] <= dp[i]) q.pop();
            q.push(i);
        }
        console.log(maxAns);
    }
}
main();