// P001512 - Binary Subarrays With Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const goal = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const count = new Map();
    count.set(0, 1);
    let sum = 0, ans = 0;
    for (let i = 0; i < n; i++) {
        sum += nums[i];
        ans += count.get(sum - goal) || 0;
        count.set(sum, (count.get(sum) || 0) + 1);
    }
    console.log(ans);
}

main();
