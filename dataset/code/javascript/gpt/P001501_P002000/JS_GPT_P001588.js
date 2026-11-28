// P001588 - Count Nice Subarrays
const fs = require("fs");

function atMostK(nums, k) {
    let l = 0, odds = 0, ans = 0;
    for (let r = 0; r < nums.length; r++) {
        if (Math.abs(nums[r] % 2) === 1) odds++;
        while (odds > k) {
            if (Math.abs(nums[l] % 2) === 1) odds--;
            l++;
        }
        ans += r - l + 1;
    }
    return ans;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    console.log(atMostK(nums, k) - atMostK(nums, k - 1));
}

main();
