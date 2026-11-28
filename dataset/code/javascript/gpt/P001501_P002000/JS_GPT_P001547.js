// P001547 - Maximum Number of Odd Elements in a Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let odds = 0;
    for (let i = 0; i < k; i++) if (Math.abs(nums[i] % 2) === 1) odds++;
    let maxOdds = odds;
    for (let i = k; i < n; i++) {
        if (Math.abs(nums[i] % 2) === 1) odds++;
        if (Math.abs(nums[i - k] % 2) === 1) odds--;
        maxOdds = Math.max(maxOdds, odds);
    }
    console.log(maxOdds);
}

main();
