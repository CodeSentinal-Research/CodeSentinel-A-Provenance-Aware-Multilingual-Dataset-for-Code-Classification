// P001491 - Minimum Difference Between Highest and Lowest of K Scores
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    nums.sort((a, b) => a - b);
    let minDiff = Infinity;
    for (let i = 0; i + k - 1 < n; i++) {
        minDiff = Math.min(minDiff, nums[i + k - 1] - nums[i]);
    }
    console.log(minDiff);
}

main();
