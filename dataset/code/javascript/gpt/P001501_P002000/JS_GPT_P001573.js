// P001573 - Count Windows With Sum Divisible by K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = BigInt(input[1]);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(BigInt(input[2 + i]));
    nums.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));
    let l = 0, total = 0n, maxFreq = 0;
    for (let r = 0; r < n; r++) {
        total += nums[r];
        while (nums[r] * BigInt(r - l + 1) - total > k) {
            total -= nums[l];
            l++;
        }
        maxFreq = Math.max(maxFreq, r - l + 1);
    }
    console.log(maxFreq);
}

main();
