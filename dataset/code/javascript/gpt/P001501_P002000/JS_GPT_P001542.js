// P001542 - Average of Every Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    const res = [curSum / k];
    for (let i = k; i < n; i++) {
        curSum += nums[i] - nums[i - k];
        res.push(curSum / k);
    }
    console.log(res.join(" "));
}

main();
