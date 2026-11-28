// P001406 - Most Frequent Number Following Key
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const key = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const counts = new Map();
    for (let i = 0; i < n - 1; i++) {
        if (nums[i] === key) {
            const target = nums[i + 1];
            counts.set(target, (counts.get(target) || 0) + 1);
        }
    }
    let bestTarget = 0, maxFreq = -1;
    for (const [target, freq] of counts.entries()) {
        if (freq > maxFreq) {
            maxFreq = freq;
            bestTarget = target;
        }
    }
    console.log(bestTarget);
}

main();
