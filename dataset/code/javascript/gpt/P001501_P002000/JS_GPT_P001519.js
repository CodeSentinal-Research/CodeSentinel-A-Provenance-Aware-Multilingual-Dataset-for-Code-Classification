// P001519 - Longest Continuous Increasing Subsequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    if (n === 0) {
        console.log(0);
        return;
    }
    let maxLen = 1, cur = 1;
    for (let i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        maxLen = Math.max(maxLen, cur);
    }
    console.log(maxLen);
}

main();
