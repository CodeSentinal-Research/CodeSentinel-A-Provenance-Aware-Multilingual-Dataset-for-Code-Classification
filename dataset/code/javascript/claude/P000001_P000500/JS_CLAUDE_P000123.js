function maxProfit(prices) {
    let minPrice = Infinity, maxProfit = 0;
    for (const p of prices) {
        minPrice = Math.min(minPrice, p);
        maxProfit = Math.max(maxProfit, p - minPrice);
    }
    return maxProfit;
}
module.exports = { maxProfit };
