// P001550 - Sum of Absolute Differences in Each Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let curDiff = 0;
    for (let i = 0; i < k - 1; i++) {
        curDiff += Math.abs(nums[i + 1] - nums[i]);
    }
    const res = [curDiff];
    for (let i = k; i < n; i++) {
        curDiff -= Math.abs(nums[i - k + 1] - nums[i - k]);
        curDiff += Math.abs(nums[i] - nums[i - 1]);
        res.push(curDiff);
    }
    console.log(res.join(" "));
}

main();
