// P001223 - Count Binary Strings Without Consecutive Ones
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const cardPoints = [];
    let totalSum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        cardPoints.push(val);
        totalSum += val;
    }
    if (k >= n) {
        console.log(totalSum);
        return;
    }
    const winSize = n - k;
    let curSum = 0;
    for (let i = 0; i < winSize; i++) curSum += cardPoints[i];
    let minSubSum = curSum;
    for (let i = winSize; i < n; i++) {
        curSum += cardPoints[i] - cardPoints[i - winSize];
        minSubSum = Math.min(minSubSum, curSum);
    }
    console.log(totalSum - minSubSum);
}

main();
