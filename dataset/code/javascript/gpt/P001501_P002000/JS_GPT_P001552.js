// P001552 - Smallest Subarray With Sum Greater Than X
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const x = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let l = 0, sum = 0, minLen = Infinity;
    for (let r = 0; r < n; r++) {
        sum += nums[r];
        while (sum > x) {
            minLen = Math.min(minLen, r - l + 1);
            sum -= nums[l];
            l++;
        }
    }
    console.log(minLen === Infinity ? 0 : minLen);
}

main();
