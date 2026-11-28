const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of matchsticks (N) and the maximum number of matchsticks (K): ', (N, K) => {
    if (N % 2 !== 0 || N < K || K > N) {
        console.log('Invalid input. Please enter an even number between 1 and 10^6 and K is less than or equal to N.');
        return;
    }

    if ((N - K) % 2 === 0) {
        console.log('FIRST');
    } else {
        console.log('SECOND');
    }

    rl.close();
});