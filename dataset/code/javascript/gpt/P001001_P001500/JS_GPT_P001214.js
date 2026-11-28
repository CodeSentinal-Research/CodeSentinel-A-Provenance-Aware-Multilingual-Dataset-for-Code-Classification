// P001214 - Strange Printer
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const stones = [];
    for (let i = 0; i < n; i++) stones.push(parseInt(input[2 + i], 10));
    if ((n - 1) % (k - 1) !== 0) {
        console.log(-1);
        return;
    }
    const prefix = [0];
    for (let i = 0; i < n; i++) prefix.push(prefix[i] + stones[i]);
    const dp = Array.from({ length: n }, () => new Array(n).fill(0));
    for (let len = k; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            dp[i][j] = Infinity;
            for (let mid = i; mid < j; mid += k - 1) {
                dp[i][j] = Math.min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
            }
            if ((len - 1) % (k - 1) === 0) {
                dp[i][j] += (prefix[j + 1] - prefix[i]);
            }
        }
    }
    console.log(dp[0][n - 1]);
}

main();
