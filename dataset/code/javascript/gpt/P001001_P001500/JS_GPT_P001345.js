// P001345 - Tug of War
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    let totalSum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        arr.push(val);
        totalSum += val;
    }
    const targetSize = Math.floor(n / 2);
    let minDiff = Infinity;
    function backtrack(idx, count, curSum) {
        if (count === targetSize) {
            const diff = Math.abs(totalSum - 2 * curSum);
            if (diff < minDiff) minDiff = diff;
            return;
        }
        if (idx === n || count + (n - idx) < targetSize) return;
        backtrack(idx + 1, count + 1, curSum + arr[idx]);
        backtrack(idx + 1, count, curSum);
    }
    backtrack(0, 0, 0);
    console.log(minDiff);
}

main();
