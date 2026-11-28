// P001483 - Max Consecutive Ones III
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let l = 0, zeros = 0, maxLen = 0;
    for (let r = 0; r < n; r++) {
        if (nums[r] === 0) zeros++;
        while (zeros > k) {
            if (nums[l] === 0) zeros--;
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
