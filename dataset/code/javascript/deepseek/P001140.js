Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = parseInt(rl.readline());

rl.on('line', (line) => {
    let [N, W] = line.split(" ").map(Number);
    let knapsack = new Array(W + 1).fill(0);
    let values = [];

    for(let i = 0; i < N; i++) {
        let [weight, value] = rl.readline().split(" ").map(Number);
        values.push({weight, value});
    }

    for(let item of values) {
        for(let i = item.weight; i <= W; i++) {
            knapsack[i] = Math.max(knapsack[i], knapsack[i-item.weight] + item.value);
        }
    }

    console.log(knapsack[W]);

    cases--;
    if(cases === 0) {
        rl.close();
    }
});
This JavaScript code reads the number of cases and the weights and values of the items from the standard input. It then constructs a dynamic programming table (an array `knapsack`) where each element `knapsack[i]` represents the maximum value that can be obtained with a total weight `i`. Afterwards, it iterates over all the items, updating the table for each item's weight and value. The maximum value is then printed to the standard output. The process repeats until all cases are processed.