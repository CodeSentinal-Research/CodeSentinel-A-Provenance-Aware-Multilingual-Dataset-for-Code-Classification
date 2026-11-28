// P001187 - Best Time to Buy and Sell Stock II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[1 + i], 10));
    let totalProfit = 0;
    for (let i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) totalProfit += (prices[i] - prices[i - 1]);
    }
    console.log(totalProfit);
}

main();
