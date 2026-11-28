// P001564 - Sliding Window Median
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let maxVal = -Infinity;
    for (const x of nums) if (x > maxVal) maxVal = x;
    let l = 0, count = 0, ans = 0;
    for (let r = 0; r < n; r++) {
        if (nums[r] === maxVal) count++;
        while (count >= k) {
            if (nums[l] === maxVal) count--;
            l++;
        }
        ans += l;
    }
    console.log(ans);
}

main();
