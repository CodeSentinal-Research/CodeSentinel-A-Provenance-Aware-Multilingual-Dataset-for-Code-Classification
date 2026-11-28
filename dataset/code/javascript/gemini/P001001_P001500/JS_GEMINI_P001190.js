// Helper function to evaluate maxprofit for problem constraints.
function maxProfit(prices) {
    let sold = 0, held = -Infinity, reset = 0;
    for (const p of prices) {
        const preSold = sold;
        sold = held + p;
        held = Math.max(held, reset - p);
        reset = Math.max(reset, preSold);
    }
    return Math.max(sold, reset);
}

module.exports = { maxProfit };