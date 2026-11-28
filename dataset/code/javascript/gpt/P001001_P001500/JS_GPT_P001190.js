// P001190 - Best Time to Buy and Sell Stock with Cooldown
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[1 + i], 10));
    let hold = -Infinity, sold = 0, rest = 0;
    for (const p of prices) {
        const prevSold = sold;
        sold = hold + p;
        hold = Math.max(hold, rest - p);
        rest = Math.max(rest, prevSold);
    }
    console.log(Math.max(sold, rest));
}

main();
