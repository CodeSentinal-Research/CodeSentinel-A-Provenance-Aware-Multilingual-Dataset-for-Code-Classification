// P001473 - 3Sum Closest
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let l = 0, r = n - 1;
    while (l < r) {
        const sum = nums[l] + nums[r];
        if (sum === target) {
            console.log(`${l + 1} ${r + 1}`);
            return;
        } else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
}

main();
