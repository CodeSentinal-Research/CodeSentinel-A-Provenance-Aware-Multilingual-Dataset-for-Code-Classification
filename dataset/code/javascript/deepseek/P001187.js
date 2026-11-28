const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N;
rl.question('Enter the number of stocks: ', (n) => {
  N = parseInt(n);
  rl.setPrompt(`Enter ${N} stock prices: `);
  rl.prompt();
});

rl.on('line', (line) => {
  const prices = line.split(' ').map(Number);

  let maxProfit = 0;
  let minPrice = prices[0];

  for (let i = 1; i < N; i++) {
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    } else if (prices[i] - minPrice > maxProfit) {
      maxProfit = prices[i] - minPrice;
    }
  }

  console.log(`Maximum profit is: ${maxProfit}`);

  rl.close();
});