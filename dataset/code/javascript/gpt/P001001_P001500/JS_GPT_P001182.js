// P001182 - Jump Game II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let jumps = 0, curEnd = 0, curFarthest = 0;
    for (let i = 0; i < n - 1; i++) {
        curFarthest = Math.max(curFarthest, i + nums[i]);
        if (i === curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    console.log(jumps);
}

main();
