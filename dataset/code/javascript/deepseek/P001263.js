Here is the JavaScript code that solves the problem:

let readline = require('readline');
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());
let costs = [];

rl.setPrompt('Enter cost for person ' + (i + 1) + ' from A to B: ');
for(let i=0; i<2*N; i++) {
    costs[i] = parseInt(rl.question());
}

costs.sort(function(a, b) {
    return a - b;
});

let minCost = Number.MAX_SAFE_INTEGER;

for(let i=0; i<N; i++) {
    minCost = Math.min(minCost, costs[i] + costs[2*N - i - 1]);
}

console.log(minCost);
rl.close();

This script reads the input, sorts the costs in ascending order and calculates the minimum cost by considering sending the people from both cities.