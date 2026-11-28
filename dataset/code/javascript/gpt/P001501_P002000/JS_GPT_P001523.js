// P001523 - Longest Subarray With Absolute Difference Within Limit
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const limit = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const maxQ = [], minQ = [];
    let l = 0, maxLen = 0;
    for (let r = 0; r < n; r++) {
        while (maxQ.length > 0 && nums[r] > maxQ[maxQ.length - 1]) maxQ.pop();
        while (minQ.length > 0 && nums[r] < minQ[minQ.length - 1]) minQ.pop();
        maxQ.push(nums[r]);
        minQ.push(nums[r]);
        while (maxQ[0] - minQ[0] > limit) {
            if (nums[l] === maxQ[0]) maxQ.shift();
            if (nums[l] === minQ[0]) minQ.shift();
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
