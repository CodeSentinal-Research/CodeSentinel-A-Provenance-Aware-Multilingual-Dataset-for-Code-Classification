// P001197 - Arithmetic Subsequences
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let total = 0;
    const dp = Array.from({ length: n }, () => new Map());
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            const diff = nums[i] - nums[j];
            const count = dp[j].get(diff) || 0;
            total += count;
            dp[i].set(diff, (dp[i].get(diff) || 0) + count + 1);
        }
    }
    console.log(total);
}

main();
