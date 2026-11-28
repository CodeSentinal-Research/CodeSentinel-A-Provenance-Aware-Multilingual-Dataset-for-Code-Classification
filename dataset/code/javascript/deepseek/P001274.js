let input = require('fs').readFileSync('stdin', 'utf8');
let lines = input.split('\n');
let N = parseInt(lines[0].split(' ')[0]);
let Coins = parseInt(lines[0].split(' ')[1]);
let costs = lines[1].split(' ').map(Number);

function maxIceCreams(N, Coins, costs) {
    // First, sort the costs in descending order
    costs.sort((a, b) => b - a);

    // Then, iterate through each cost
    for (let i = 0; i < N; i++) {
        // If the current cost exceeds the number of coins, return the count of bars bought so far
        if (costs[i] > Coins) {
            return i;
        }
        // If not, add the cost to Coins and continue with the next cost
        Coins -= costs[i];
    }
    // If all costs are less than or equal to Coins, return N
    return N;
}

console.log(maxIceCreams(N, Coins, costs));