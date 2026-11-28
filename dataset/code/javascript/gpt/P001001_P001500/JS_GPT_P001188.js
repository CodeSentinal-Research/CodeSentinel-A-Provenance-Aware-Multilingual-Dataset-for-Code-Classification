// P001188 - Best Time to Buy and Sell Stock III
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[1 + i], 10));
    let buy1 = -Infinity, sell1 = 0;
    let buy2 = -Infinity, sell2 = 0;
    for (const p of prices) {
        buy1 = Math.max(buy1, -p);
        sell1 = Math.max(sell1, buy1 + p);
        buy2 = Math.max(buy2, sell1 - p);
        sell2 = Math.max(sell2, buy2 + p);
    }
    console.log(sell2);
}

main();
