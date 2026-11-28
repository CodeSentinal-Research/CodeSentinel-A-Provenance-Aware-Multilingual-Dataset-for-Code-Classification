// P001517 - Minimize Maximum Pair Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    nums.sort((a, b) => a - b);
    let maxPairSum = 0;
    for (let i = 0; i < n / 2; i++) {
        maxPairSum = Math.max(maxPairSum, nums[i] + nums[n - 1 - i]);
    }
    console.log(maxPairSum);
}

main();
