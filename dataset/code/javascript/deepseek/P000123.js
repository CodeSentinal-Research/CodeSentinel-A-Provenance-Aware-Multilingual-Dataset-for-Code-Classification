Here's a simple JavaScript solution for the problem:

function maxProfit(prices) {
    let minPrice = prices[0];
    let maxProfit = 0;
    
    for(let i = 1; i < prices.length; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}

// Example usage:
console.log(maxProfit([7,1,5,3,6,4])); // Output: 5

In this solution, we use two variables `minPrice` and `maxProfit`. `minPrice` keeps track of the minimum price we have seen so far and `maxProfit` keeps track of the maximum profit we can get by selling at the current price.

The logic is that we iterate through the prices array and for each price, if the price is less than our current minimum price, we update our minimum price. If the current price is greater than our minimum price and the current price minus the minimum price is greater than our current maximum profit, we update our maximum profit.

Finally, we return the maximum profit.