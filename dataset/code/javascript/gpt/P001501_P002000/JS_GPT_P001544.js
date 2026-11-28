// P001544 - Count Windows With Sum Greater Than X
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const x = parseInt(input[2], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[3 + i], 10));
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let count = 0;
    if (curSum > x) count++;
    for (let i = k; i < n; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum > x) count++;
    }
    console.log(count);
}

main();
