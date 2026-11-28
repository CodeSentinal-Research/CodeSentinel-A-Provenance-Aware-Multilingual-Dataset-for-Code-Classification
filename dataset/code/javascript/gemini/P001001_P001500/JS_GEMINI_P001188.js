// Helper function to evaluate maxprofit for problem constraints.
function maxProfit(prices) {
    let buy1 = Infinity, buy2 = Infinity;
    let profit1 = 0, profit2 = 0;

    for (const p of prices) {
        buy1 = Math.min(buy1, p);
        profit1 = Math.max(profit1, p - buy1);
        buy2 = Math.min(buy2, p - profit1);
        profit2 = Math.max(profit2, p - buy2);
    }
    return profit2;
}

module.exports = { maxProfit };