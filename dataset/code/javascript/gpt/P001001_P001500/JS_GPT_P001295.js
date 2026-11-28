// P001295 - Put Marbles in Bags
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const weights = [];
    for (let i = 0; i < n; i++) weights.push(parseInt(input[2 + i], 10));
    if (k === 1 || k === n) { console.log(0); return; }
    const pairSums = [];
    for (let i = 0; i < n - 1; i++) pairSums.push(weights[i] + weights[i + 1]);
    pairSums.sort((a, b) => a - b);
    let minScore = 0, maxScore = 0;
    for (let i = 0; i < k - 1; i++) {
        minScore += pairSums[i];
        maxScore += pairSums[pairSums.length - 1 - i];
    }
    console.log(maxScore - minScore);
}

main();
