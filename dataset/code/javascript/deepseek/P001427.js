const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter a number: ', (n) => {
  if (n < 1 || n > 100000) {
    console.log('Invalid input. Please enter a number between 1 and 100000.');
    rl.close();
    return;
  }

  const digitSums = Array(n + 1).fill(0).map((_, i) => {
    let sum = 0;
    let num = i;
    while (num != 0) {
      sum += num % 10;
      num = Math.floor(num / 10);
    }
    return sum;
  });

  let max = 0;
  let maxCount = 0;
  let count = 0;
  for (let i = 1; i <= n; i++) {
    const sum = digitSums[i];
    if (sum > max) {
      max = sum;
      maxCount = count;
      count = 1;
    } else if (sum === max) {
      count++;
    }
  }

  if (max === 0) {
    console.log('No group found with maximum sum.');
  } else {
    console.log(maxCount);
  }

  rl.close();
});