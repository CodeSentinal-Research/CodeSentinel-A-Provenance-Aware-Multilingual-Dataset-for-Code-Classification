// P001522 - Minimum Operations to Reduce X to Zero
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const x = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let total = 0;
    for (const v of nums) total += v;
    const target = total - x;
    if (target < 0) {
        console.log(-1);
        return;
    }
    if (target === 0) {
        console.log(n);
        return;
    }
    let cur = 0, l = 0, maxLen = -1;
    for (let r = 0; r < n; r++) {
        cur += nums[r];
        while (cur > target && l <= r) {
            cur -= nums[l];
            l++;
        }
        if (cur === target) {
            maxLen = Math.max(maxLen, r - l + 1);
        }
    }
    console.log(maxLen === -1 ? -1 : n - maxLen);
}

main();
