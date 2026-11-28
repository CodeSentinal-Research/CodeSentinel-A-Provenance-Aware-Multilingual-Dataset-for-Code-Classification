Here is the JavaScript code for the problem:

function maxProfit(prices, fee) {
    let buy = -prices[0], sell = 0;
    for (let i = 1; i < prices.length; i++) {
        buy = Math.max(buy, sell - prices[i]);
        sell = Math.max(sell, buy + prices[i] - fee);
    }
    return sell;
}

let prices = [1, 3, 2, 8, 4, 9, 7];
let fee = 2;
console.log(maxProfit(prices, fee));

In this code, we use the concept of two variables `buy` and `sell` to keep track of the maximum profit we can get by buying and selling at different times. `buy` is initialized to `-prices[0]`, because we cannot buy at the first day if we don't have any money at that time. `sell` is initialized to `0` as the maximum profit at the end is `0`.

Then we loop through the `prices` array from the second day to the end. For each day, we calculate the `buy` and `sell` values as follows:

- `buy`: this is the maximum profit we can get if we decide to buy the stock on the current day, which is the price at the current day minus the transaction fee.

- `sell`: this is the maximum profit we can get if we decide to sell the stock on the current day, which is the maximum between the following two things:
    - the maximum profit we can get if we decide to sell the stock on the previous day, which is the `sell` value at the previous day minus the price at the current day.
    - the maximum profit we can get if we decide to buy the stock on the previous day, which is the `buy` value at the previous day plus the price at the current day minus the transaction fee.

Finally, we return `sell` which is the maximum profit we can get by selling the stock on the last day.