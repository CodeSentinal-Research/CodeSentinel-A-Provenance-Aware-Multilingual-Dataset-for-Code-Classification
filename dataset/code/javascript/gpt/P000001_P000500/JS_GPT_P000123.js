// P000123 - Best Time to Buy and Sell Stock
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const prices = tokens.slice(p, p + n);
let minPrice = Infinity, maxProfit = 0;
for (const price of prices) {
    minPrice = Math.min(minPrice, price);
    maxProfit = Math.max(maxProfit, price - minPrice);
}
console.log(maxProfit);
