// P001171 - Unique Paths
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const m = parseInt(input[0], 10);
    const n = parseInt(input[1], 10);
    const dp = new Array(n).fill(1n);
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    console.log(dp[n - 1].toString());
}

main();
