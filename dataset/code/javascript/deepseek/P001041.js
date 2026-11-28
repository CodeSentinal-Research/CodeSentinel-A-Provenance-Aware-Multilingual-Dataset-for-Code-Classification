Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = parseInt(rl.readline());

rl.on('line', (line) => {
    let [N, K] = line.split(" ").map(Number);
    let quality = rl.readline().split(" ").map(Number);
    let wage = rl.readline().split(" ").map(Number);

    let totalCost = 0;

    // sort quality array in descending order
    quality.sort((a, b) => b - a);
    // sort wage array in ascending order
    wage.sort((a, b) => a - b);

    // loop through each worker and add the minimum wage that is greater than the current quality to totalCost
    for(let i = 0; i < K; i++) {
        if(quality[i] < wage[i]) {
            totalCost += wage[i];
        } else {
            totalCost += quality[i];
        }
    }

    console.log(totalCost);

    if(cases > 1) {
        console.log('');
    }
});

rl.close();

This program reads the number of cases, then for each case it reads the number of workers, their quality and minimum wage, sorts the quality and wage arrays and calculates the total cost. The cost is printed out.