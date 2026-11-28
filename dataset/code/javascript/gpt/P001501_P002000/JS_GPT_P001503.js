// P001503 - Minimum Adjacent Swaps for K Consecutive Ones
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const p = [];
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) p.push(i - p.length);
    }
    const m = p.length;
    const prefix = new Array(m + 1).fill(0);
    for (let i = 0; i < m; i++) prefix[i + 1] = prefix[i] + p[i];
    let ans = Infinity;
    const mid = Math.floor(k / 2);
    for (let i = 0; i <= m - k; i++) {
        const leftSum = prefix[i + mid] - prefix[i];
        const rightSum = prefix[i + k] - prefix[i + mid];
        const median = p[i + mid];
        const cost = (median * mid - leftSum) + (rightSum - median * (k - mid));
        ans = Math.min(ans, cost);
    }
    console.log(ans);
}

main();
