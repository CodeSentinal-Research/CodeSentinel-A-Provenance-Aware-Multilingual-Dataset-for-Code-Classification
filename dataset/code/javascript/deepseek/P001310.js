const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.question('Enter number of sticks: ', (N) => {
    rl.question('Enter stick lengths: ', (line) => {
        const sticks = line.split(' ').map(Number);

        sticks.sort((a, b) => a - b);

        let minCost = 0;

        for (let i = 1; i < N; i++) {
            minCost += sticks[i - 1] + sticks[i];
        }

        console.log(minCost);

        rl.close();
    });
});