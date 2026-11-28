Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases;
rl.once('line', (line) => {
    cases = parseInt(line);
    let horizontalCuts = [];
    let verticalCuts = [];
    for(let i = 0; i < cases - 1; i++) {
        rl.once('line', (line) => {
            horizontalCuts.push(parseInt(line));
        });
    }
    for(let i = 0; i < cases - 1; i++) {
        rl.once('line', (line) => {
            verticalCuts.push(parseInt(line));
        });
    }

    let minHorizontalCutCost = Math.min(...horizontalCuts);
    let minVerticalCutCost = Math.min(...verticalCuts);

    let minCost = Math.min(minHorizontalCutCost * (cases - 1) + minVerticalCutCost,
        minHorizontalCutCost + minVerticalCutCost + (cases - 1) * Math.max(...horizontalCuts, ...verticalCuts));

    console.log(minCost);

    rl.close();
});

This code will prompt for user input for the number of cases, and then for the costs of horizontal and vertical cuts, respectively. It will then calculate the minimum total cost required to cut the entire board.