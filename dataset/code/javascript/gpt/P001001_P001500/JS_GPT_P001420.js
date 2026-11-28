// P001420 - Longest Arithmetic Subsequence With Given Difference
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const dp = new Array(n).fill(-1);
    dp[0] = 0;
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (dp[j] !== -1 && Math.abs(nums[i] - nums[j]) <= target) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    console.log(dp[n - 1]);
}

main();
