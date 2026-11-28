Sure, here's the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs = line.split(' ');
    rl.close();
});

rl.on('close', () => {
    const [M, N] = inputs;
    M = parseInt(M);
    N = parseInt(N);

    if (M === 1) {
        console.log(1);
    } else {
        console.log(N - M + 1);
    }
});

This script reads an array of M sorted positive integers and an integer N from the input. It then calculates and prints the minimum number of additional numbers that must be inserted to ensure that every number in the range [1, N] can be formed as a sum of some subset of the array.