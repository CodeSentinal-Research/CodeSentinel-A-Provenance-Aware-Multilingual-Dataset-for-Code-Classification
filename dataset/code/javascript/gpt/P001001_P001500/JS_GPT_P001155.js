// P001155 - Burst Balloons
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [1];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    nums.push(1);
    const len = nums.length;
    const dp = Array.from({ length: len }, () => new Array(len).fill(0));
    for (let k = 2; k < len; k++) {
        for (let left = 0; left < len - k; left++) {
            const right = left + k;
            for (let i = left + 1; i < right; i++) {
                dp[left][right] = Math.max(
                    dp[left][right],
                    nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]
                );
            }
        }
    }
    console.log(dp[0][len - 1]);
}

main();
