// P001545 - Minimum Difference Between Maximum and Minimum in Every Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let minDiff = Infinity;
    for (let i = 0; i + k <= n; i++) {
        let maxV = -Infinity, minV = Infinity;
        for (let j = i; j < i + k; j++) {
            maxV = Math.max(maxV, nums[j]);
            minV = Math.min(minV, nums[j]);
        }
        minDiff = Math.min(minDiff, maxV - minV);
    }
    console.log(minDiff);
}

main();
