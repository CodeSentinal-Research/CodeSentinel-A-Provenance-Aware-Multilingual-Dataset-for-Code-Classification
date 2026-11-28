// P001191 - Best Time to Buy and Sell Stock with Transaction Fee
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const fee = parseInt(input[1], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[2 + i], 10));
    let hold = -prices[0], cash = 0;
    for (let i = 1; i < n; i++) {
        cash = Math.max(cash, hold + prices[i] - fee);
        hold = Math.max(hold, cash - prices[i]);
    }
    console.log(cash);
}

main();
