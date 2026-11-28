// P001184 - Frog Jump with K Distance
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const heights = [];
    for (let i = 0; i < n; i++) heights.push(parseInt(input[2 + i], 10));
    const dp = new Array(n).fill(Infinity);
    dp[0] = 0;
    for (let i = 1; i < n; i++) {
        for (let j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = Math.min(dp[i], dp[i - j] + Math.abs(heights[i] - heights[i - j]));
            }
        }
    }
    console.log(dp[n - 1]);
}

main();
