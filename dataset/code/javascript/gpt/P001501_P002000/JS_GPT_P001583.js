// P001583 - Count Subarrays With At Most K Distinct Integers
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const count = new Map();
    let l = 0, ans = 0;
    for (let r = 0; r < n; r++) {
        count.set(nums[r], (count.get(nums[r]) || 0) + 1);
        while (count.size > k) {
            const c = count.get(nums[l]) - 1;
            if (c === 0) count.delete(nums[l]);
            else count.set(nums[l], c);
            l++;
        }
        ans += r - l + 1;
    }
    console.log(ans);
}

main();
