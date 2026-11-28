// P001142 - Partition Equal Subset Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    let sum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        nums.push(val);
        sum += val;
    }
    if (sum % 2 !== 0) {
        console.log("NO");
        return;
    }
    const target = sum / 2;
    const dp = new Array(target + 1).fill(false);
    dp[0] = true;
    for (const num of nums) {
        for (let j = target; j >= num; j--) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    console.log(dp[target] ? "YES" : "NO");
}

main();
