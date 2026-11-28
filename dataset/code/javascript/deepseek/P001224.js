Here is the JavaScript code for the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of tiles: ', (n) => {
    rl.close();

    // The total number of ways to tile the 2xn board is the nth number in the Fibonacci sequence.
    // Fibonacci sequence is a sequence of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1.
    console.log(fibonacci(n));
});

function fibonacci(n) {
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return 1;
    }
    if (n === 2) {
        return 2;
    }
    let fib = [0, 1, 2];
    for (let i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
This code uses the Fibonacci sequence to solve the problem. The `fibonacci` function generates the Fibonacci sequence up to the `n`th number. It uses an array to store the computed values, so it doesn't re-compute the same values multiple times.

The `readline` module from Node.js is used to get the user input. It reads a line from `stdin`, and then calls the callback function with the user's input as the argument. The callback function prints the result to `stdout`.