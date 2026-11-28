// P001001 - Find the Kth Largest Element
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) {
        nums.push(parseInt(input[2 + i], 10));
    }
    nums.sort((a, b) => b - a);
    console.log(nums[k - 1]);
}

main();
