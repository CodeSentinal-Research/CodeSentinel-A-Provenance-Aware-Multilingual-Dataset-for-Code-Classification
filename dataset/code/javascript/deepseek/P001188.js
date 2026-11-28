Here's a simple JavaScript solution for the problem using dynamic programming:

function maxProfit(prices) {
    let n = prices.length;
    if (n < 2) {
        return 0;
    }

    let buy1 = -prices[0], buy2 = -prices[0];
    let sell1 = 0, sell2 = 0;

    for (let i = 1; i < n; i++) {
        buy1 = Math.max(buy1, -prices[i]);
        sell1 = Math.max(sell1, buy1 + prices[i]);
        buy2 = Math.max(buy2, sell1 - prices[i]);
        sell2 = Math.max(sell2, buy2 + prices[i]);
    }

    return sell2;
}

function solve() {
    let N = parseInt(readline());
    let prices = readline().split(' ').map(Number);
    console.log(maxProfit(prices));
}
This script reads the number of prices (N), and the prices themselves, and then calls the `maxProfit` function to find the maximum profit from at most two buy-sell transactions.