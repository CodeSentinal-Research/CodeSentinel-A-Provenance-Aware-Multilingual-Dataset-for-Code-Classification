// Helper function to evaluate maxprofit for problem constraints.
function maxProfit(k, prices) {
    if (!prices || prices.length === 0 || k === 0) return 0;
    const n = prices.length;
    if (k >= Math.floor(n / 2)) {
        let res = 0;
        for (let i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
        }
        return res;
    }

    const buy = new Array(k + 1).fill(Infinity);
    const profit = new Array(k + 1).fill(0);

    for (const p of prices) {
        for (let i = 1; i <= k; i++) {
            buy[i] = Math.min(buy[i], p - profit[i - 1]);
            profit[i] = Math.max(profit[i], p - buy[i]);
        }
    }
    return profit[k];
}

module.exports = { maxProfit };