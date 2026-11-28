// P001166 - Maximum Circular Subarray Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    let totalSum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        nums.push(val);
        totalSum += val;
    }
    let curMax = 0, maxSub = -Infinity;
    let curMin = 0, minSub = Infinity;
    for (const x of nums) {
        curMax = Math.max(x, curMax + x);
        maxSub = Math.max(maxSub, curMax);
        curMin = Math.min(x, curMin + x);
        minSub = Math.min(minSub, curMin);
    }
    if (maxSub < 0) {
        console.log(maxSub);
    } else {
        console.log(Math.max(maxSub, totalSum - minSub));
    }
}

main();
