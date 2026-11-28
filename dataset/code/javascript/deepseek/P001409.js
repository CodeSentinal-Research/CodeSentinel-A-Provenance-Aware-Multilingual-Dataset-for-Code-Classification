Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N, K;

rl.on('line', function(line) {
    [N, K] = line.split(' ');
    N = parseInt(N);
    K = parseInt(K);
});

rl.on('close', function() {
    process.stdin.close();
    solve(N, K);
});

function solve(N, K) {
    // Your code goes here
}

In this code, we use the readline module to read input from the console. We define variables N and K, and then we read N and K from the console. After that, we define a function solve(N, K) which will be the main function that will be called after the input is read.