// P001144 - Longest Increasing Subsequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const tails = [];
    for (const x of nums) {
        let low = 0, high = tails.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (tails[mid] < x) low = mid + 1;
            else high = mid;
        }
        if (low === tails.length) tails.push(x);
        else tails[low] = x;
    }
    console.log(tails.length);
}

main();
