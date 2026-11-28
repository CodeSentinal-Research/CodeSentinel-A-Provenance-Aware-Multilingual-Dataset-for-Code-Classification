// P001567 - Count Complete Subarrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const count = new Map();
    let sum = 0, maxSum = 0;
    for (let i = 0; i < n; i++) {
        count.set(nums[i], (count.get(nums[i]) || 0) + 1);
        sum += nums[i];
        if (i >= k) {
            const out = nums[i - k];
            const c = count.get(out) - 1;
            if (c === 0) count.delete(out);
            else count.set(out, c);
            sum -= out;
        }
        if (i >= k - 1 && count.size === k) {
            maxSum = Math.max(maxSum, sum);
        }
    }
    console.log(maxSum);
}

main();
