// P001288 - Maximum Equal Sum After K Negations
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    nums.sort((a, b) => a - b);
    if (k % 2 === 1) nums[0] = -nums[0];
    let sum = 0;
    for (const x of nums) sum += x;
    console.log(sum);
}

main();
