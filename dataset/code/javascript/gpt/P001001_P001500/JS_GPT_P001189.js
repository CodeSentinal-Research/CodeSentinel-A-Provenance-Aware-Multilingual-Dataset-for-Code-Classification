// P001189 - Best Time to Buy and Sell Stock IV
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const k = parseInt(input[0], 10);
    const n = parseInt(input[1], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[2 + i], 10));
    if (n === 0) { console.log(0); return; }
    if (k >= Math.floor(n / 2)) {
        let prof = 0;
        for (let i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) prof += (prices[i] - prices[i - 1]);
        }
        console.log(prof);
        return;
    }
    const buy = new Array(k + 1).fill(-Infinity);
    const sell = new Array(k + 1).fill(0);
    for (const p of prices) {
        for (let j = 1; j <= k; j++) {
            buy[j] = Math.max(buy[j], sell[j - 1] - p);
            sell[j] = Math.max(sell[j], buy[j] + p);
        }
    }
    console.log(sell[k]);
}

main();
