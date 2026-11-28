// P001525 - Longest Continuous Subarray With Equal Number of Even and Odd Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const map = new Map();
    map.set(0, -1);
    let balance = 0, maxLen = 0;
    for (let i = 0; i < n; i++) {
        balance += (nums[i] % 2 === 0) ? 1 : -1;
        if (map.has(balance)) {
            maxLen = Math.max(maxLen, i - map.get(balance));
        } else {
            map.set(balance, i);
        }
    }
    console.log(maxLen);
}

main();
