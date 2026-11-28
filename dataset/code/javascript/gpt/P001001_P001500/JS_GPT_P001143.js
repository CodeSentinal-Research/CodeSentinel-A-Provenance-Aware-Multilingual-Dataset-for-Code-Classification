// P001143 - Target Sum Expressions
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const nums = [];
    let sum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        nums.push(val);
        sum += val;
    }
    if ((sum + target) < 0 || (sum + target) % 2 !== 0) {
        console.log(0);
        return;
    }
    const s1 = (sum + target) / 2;
    const dp = new Array(s1 + 1).fill(0n);
    dp[0] = 1n;
    for (const num of nums) {
        for (let j = s1; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    console.log(dp[s1].toString());
}

main();
