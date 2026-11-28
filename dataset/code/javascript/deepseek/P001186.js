Here's the JavaScript code to solve the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question().trim());
let stocks = [];

rl.on('line', function(line) {
    stocks.push(parseInt(line.trim()));
    if (stocks.length === N) {
        let maxProfit = maxProfit(stocks);
        console.log(maxProfit);
        rl.close();
    }
});

function maxProfit(arr) {
    let minPrice = arr[0];
    let maxProfit = arr[1] - arr[0];
    for(let i = 1; i < arr.length; i++){
        minPrice = Math.min(minPrice, arr[i]);
        maxProfit = Math.max(maxProfit, arr[i] - minPrice);
   
    }
    return maxProfit;
}
This code will ask for the number of stocks as input from the user. Then it will ask for each stock price one by one. As soon as all prices are provided, it will calculate the maximum profit from buying at the minimum price and selling at the maximum price.