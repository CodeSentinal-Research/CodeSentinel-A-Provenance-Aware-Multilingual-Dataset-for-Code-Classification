Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = [];

rl.on('line', function(line) {
    cases.push(line.split(' '));
}).on('close', function() {
    cases.forEach(c => solve(c[0], c[1], c[2]));
});

function solve(N, weights, boatCapacities) {
    let n = Number(N);
    let weightsArr = weights.split(' ').map(Number);
    let capacitiesArr = boatCapacities.split(' ').map(Number);

    weightsArr.sort((a, b) => a - b);
    capacitiesArr.sort((a, b) => a - b);

    let i = 0;
    let j = n - 1;
    let boats = 0;

    while (i <= j) {
        if (weightsArr[i] + weightsArr[j] <= capacitiesArr[j]) {
            boats++;
            j--;
        } else {
            boats++;
        }
        i++;
    }

    if (boats > capacitiesArr[j]) {
        console.log(-1);
    } else {
        console.log(boats);
    }
}
This code reads the input from the standard input and then calls the solve function with the input data. The solve function first sorts the weights and capacities of the people and boats, then it iterates through the sorted weights and capacities, and tries to rescue the people in the order they are sorted by weight. If a person can be rescued with the current boat, it increments the number of boats and moves to the next person. If a person can't be rescued with the current boat, it increments the number of boats but doesn't move to the next person. If the number of boats exceed the capacity of the current boat, it returns -1. Otherwise, it returns the number of boats.