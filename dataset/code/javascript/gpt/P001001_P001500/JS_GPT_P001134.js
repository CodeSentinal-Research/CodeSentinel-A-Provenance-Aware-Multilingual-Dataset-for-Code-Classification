// P001134 - House Robber
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    if (n === 0) { console.log(0); return; }
    if (n === 1) { console.log(nums[0]); return; }
    let prev2 = 0, prev1 = nums[0];
    for (let i = 1; i < n; i++) {
        const curr = Math.max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    console.log(prev1);
}

main();
