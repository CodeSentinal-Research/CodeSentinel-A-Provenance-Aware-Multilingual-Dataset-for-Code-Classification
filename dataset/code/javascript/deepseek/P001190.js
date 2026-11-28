Here is the JavaScript code for the problem:

process.stdin.on('data', function(data) {
    var N = parseInt(data);
    var prices = [];
    for(var i = 0; i < N; i++) {
        prices.push(parseInt(process.stdin.read()));
    }

    var hold = -prices[0];
    var sell = 0;
    var cooldown = 0;

    for(var i = 1; i < N; i++) {
        var newSell = Math.max(sell, hold + prices[i] - cooldown);
        var newCooldown = Math.max(cooldown, hold + prices[i] - sell);
        var newHold = Math.max(hold, cooldown - prices[i]);
        sell = newSell;
        cooldown = newCooldown;
        hold = newHold;
    }

    console.log(Math.max(sell, cooldown));
});

This program reads the number of days and daily stock prices from the standard input, then computes the maximum profit by selling a stock, cooldown, and holding a stock. The variable `hold` represents the maximum profit we can get if we hold a stock, `sell` is the maximum profit we can get if we sell a stock, and `cooldown` is the maximum profit we can get if we cooldown after a sale. After each iteration, we update these variables to reflect the maximum profit we can get in the current state. Finally, we output the maximum profit among the three states, which is the maximum profit we can get if we sell a stock and cooldown after each sale.