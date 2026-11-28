// P001541 - Maximum Sum of K Consecutive Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let maxSum = curSum;
    for (let i = k; i < n; i++) {
        curSum += nums[i] - nums[i - k];
        maxSum = Math.max(maxSum, curSum);
    }
    console.log(maxSum);
}

main();
