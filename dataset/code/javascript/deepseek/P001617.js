Here is the JavaScript code that handles the problem:

let readline = require('readline');

let input = [];
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function(line) {
    input.push(parseInt(line));
});

rl.on('close', function() {
    solve(input);
});

function solve(input) {
    let count = 0;
    let sum = 0;
    for (let i = 0; i < input.length; i++) {
        sum += input[i];
        if (sum % 2 === 0) {
            count++;
        }
    }
    console.log(count);
}

This code reads the input as an array of integers from the standard input, and then solves the problem by iterating over the input array and incrementing a counter each time the sum of the current prefix is even. The count is then printed to the standard output.