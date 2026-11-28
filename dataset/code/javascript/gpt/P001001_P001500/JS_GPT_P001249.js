// P001249 - Minimum Cost to Connect Ropes
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    if (n < 2) { console.log(n); return; }
    let up = 1, down = 1;
    for (let i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) up = down + 1;
        else if (nums[i] < nums[i - 1]) down = up + 1;
    }
    console.log(Math.max(up, down));
}

main();
