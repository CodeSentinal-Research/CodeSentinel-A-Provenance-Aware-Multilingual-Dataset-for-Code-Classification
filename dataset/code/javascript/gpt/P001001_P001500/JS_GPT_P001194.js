// P001194 - Partition Array for Maximum Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[2 + i], 10));
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        let maxVal = 0;
        for (let j = 1; j <= Math.min(k, i); j++) {
            maxVal = Math.max(maxVal, arr[i - j]);
            dp[i] = Math.max(dp[i], dp[i - j] + maxVal * j);
        }
    }
    console.log(dp[n]);
}

main();
