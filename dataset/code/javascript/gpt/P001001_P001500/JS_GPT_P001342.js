// P001342 - Count Increasing Subsequences of Length K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const dp = Array.from({ length: k + 1 }, () => new Array(n).fill(0n));
    for (let i = 0; i < n; i++) dp[1][i] = 1n;
    for (let len = 2; len <= k; len++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[len][i] += dp[len - 1][j];
                }
            }
        }
    }
    let total = 0n;
    for (let i = 0; i < n; i++) total += dp[k][i];
    console.log(total.toString());
}

main();
