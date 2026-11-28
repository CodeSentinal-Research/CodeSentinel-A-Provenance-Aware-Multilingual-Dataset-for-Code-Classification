// P001546 - Longest Alternating Even-Odd Subarray
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let maxLen = 1, cur = 1;
    for (let i = 1; i < n; i++) {
        if (Math.abs(nums[i] % 2) !== Math.abs(nums[i - 1] % 2)) {
            cur++;
        } else {
            cur = 1;
        }
        maxLen = Math.max(maxLen, cur);
    }
    console.log(maxLen);
}

main();
