// P001562 - Longest Substring With Exactly K Distinct Characters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const cardPoints = [];
    for (let i = 0; i < n; i++) cardPoints.push(parseInt(input[2 + i], 10));
    let total = 0;
    for (const x of cardPoints) total += x;
    if (k === n) {
        console.log(total);
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
    console.log(total - minSubSum);
}

main();
