// P001551 - Longest Subarray With Sum Less Than or Equal to K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let l = 0, sum = 0, maxLen = 0;
    for (let r = 0; r < n; r++) {
        sum += nums[r];
        while (sum > k && l <= r) {
            sum -= nums[l];
            l++;
        }
        if (sum <= k) {
            maxLen = Math.max(maxLen, r - l + 1);
        }
    }
    console.log(maxLen);
}

main();
