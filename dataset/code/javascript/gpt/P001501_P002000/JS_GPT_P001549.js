// P001549 - Count Windows With All Positive Numbers
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let nonPos = 0;
    for (let i = 0; i < k; i++) if (nums[i] <= 0) nonPos++;
    let count = 0;
    if (nonPos === 0) count++;
    for (let i = k; i < n; i++) {
        if (nums[i] <= 0) nonPos++;
        if (nums[i - k] <= 0) nonPos--;
        if (nonPos === 0) count++;
    }
    console.log(count);
}

main();
