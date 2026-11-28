// P001192 - House Robber II
const fs = require("fs");

function robLinear(nums) {
    let prev2 = 0, prev1 = 0;
    for (const x of nums) {
        const curr = Math.max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    if (n === 1) { console.log(nums[0]); return; }
    const ans1 = robLinear(nums.slice(0, n - 1));
    const ans2 = robLinear(nums.slice(1));
    console.log(Math.max(ans1, ans2));
}

main();
