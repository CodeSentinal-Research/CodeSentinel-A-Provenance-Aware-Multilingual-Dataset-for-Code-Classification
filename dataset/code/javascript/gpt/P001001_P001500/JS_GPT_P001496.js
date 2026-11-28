// P001496 - Apply Operations to an Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    for (let i = 0; i < n - 1; i++) {
        if (nums[i] === nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    const nonZeros = [], zeros = [];
    for (const x of nums) {
        if (x !== 0) nonZeros.push(x);
        else zeros.push(x);
    }
    console.log([...nonZeros, ...zeros].join(" "));
}

main();
