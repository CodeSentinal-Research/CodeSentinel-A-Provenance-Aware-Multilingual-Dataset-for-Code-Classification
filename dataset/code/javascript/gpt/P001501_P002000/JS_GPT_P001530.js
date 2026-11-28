// P001530 - Maximum Erasure Value
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const seen = new Set();
    let l = 0, sum = 0, maxSum = 0;
    for (let r = 0; r < n; r++) {
        while (seen.has(nums[r])) {
            seen.delete(nums[l]);
            sum -= nums[l];
            l++;
        }
        seen.add(nums[r]);
        sum += nums[r];
        maxSum = Math.max(maxSum, sum);
    }
    console.log(maxSum);
}

main();
