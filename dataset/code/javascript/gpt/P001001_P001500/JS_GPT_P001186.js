// P001186 - Best Time to Buy and Sell Stock I
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const prices = [];
    for (let i = 0; i < n; i++) prices.push(parseInt(input[1 + i], 10));
    let minPrice = Infinity, maxProfit = 0;
    for (const p of prices) {
        if (p < minPrice) minPrice = p;
        else if (p - minPrice > maxProfit) maxProfit = p - minPrice;
    }
    console.log(maxProfit);
}

main();
