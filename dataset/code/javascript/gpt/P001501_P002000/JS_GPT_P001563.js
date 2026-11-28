// P001563 - Longest Subarray With Absolute Difference Within Limit
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const count = new Map();
    let l = 0, maxLen = 0;
    for (let r = 0; r < n; r++) {
        count.set(nums[r], (count.get(nums[r]) || 0) + 1);
        while (true) {
            let minV = Infinity, maxV = -Infinity;
            for (const k of count.keys()) {
                minV = Math.min(minV, k);
                maxV = Math.max(maxV, k);
            }
            if (maxV - minV <= 1) break;
            const c = count.get(nums[l]) - 1;
            if (c === 0) count.delete(nums[l]);
            else count.set(nums[l], c);
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
