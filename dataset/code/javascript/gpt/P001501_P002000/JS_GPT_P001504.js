// P001504 - Longest Nice Subarray
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let used = 0, l = 0, maxLen = 0;
    for (let r = 0; r < n; r++) {
        while ((used & nums[r]) !== 0) {
            used ^= nums[l];
            l++;
        }
        used |= nums[r];
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
