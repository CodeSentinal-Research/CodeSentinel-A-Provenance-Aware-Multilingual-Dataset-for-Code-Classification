// P001515 - Count Alternating Subarrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let ans = 0, len = 1;
    for (let i = 0; i < n; i++) {
        if (i > 0 && nums[i] !== nums[i - 1]) {
            len++;
        } else {
            len = 1;
        }
        ans += len;
    }
    console.log(ans);
}

main();
