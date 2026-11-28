// P001140 - Unbounded Knapsack
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const w = parseInt(input[1], 10);
    let ptr = 2;
    const weights = [];
    for (let i = 0; i < n; i++) weights.push(parseInt(input[ptr++], 10));
    const values = [];
    for (let i = 0; i < n; i++) values.push(parseInt(input[ptr++], 10));
    const dp = new Array(w + 1).fill(0);
    for (let i = 0; i < n; i++) {
        for (let j = weights[i]; j <= w; j++) {
            dp[j] = Math.max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    console.log(dp[w]);
}

main();
