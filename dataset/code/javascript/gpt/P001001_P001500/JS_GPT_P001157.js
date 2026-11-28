// P001157 - Rod Cutting
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[1 + i], 10));
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        let maxVal = 0;
        for (let j = 0; j < i; j++) {
            maxVal = Math.max(maxVal, prices[j] + dp[i - j - 1]);
        }
        dp[i] = maxVal;
    }
    console.log(dp[n]);
}

main();
