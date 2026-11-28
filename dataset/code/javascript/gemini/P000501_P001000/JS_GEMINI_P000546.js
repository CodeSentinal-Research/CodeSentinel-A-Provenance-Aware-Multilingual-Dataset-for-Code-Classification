const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const s = tokens[0];
        const minJump = parseInt(tokens[1], 10);
        const maxJump = parseInt(tokens[2], 10);
        const n = s.length;
        if (s[n - 1] !== '0') { console.log("false"); return; }
        // dp table storing optimal subproblem solutions
        const dp = new Array(n).fill(false);
        // Update dynamic programming state transition
        dp[0] = true;
        let reach = 0;
        for (let i = 0; i < n; i++) {
            if (!dp[i]) continue;
            const start = Math.max(i + minJump, reach + 1);
            const end = Math.min(i + maxJump, n - 1);
            for (let j = start; j <= end; j++) {
                // Update dynamic programming state transition
                if (s[j] === '0') dp[j] = true;
            }
            reach = Math.max(reach, end);
        }
        console.log(dp[n - 1] ? "true" : "false");
    }
}
main();