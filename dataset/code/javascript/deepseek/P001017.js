Here is the JavaScript solution:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.question('Enter the number of ropes: ', (n) => {
    N = parseInt(n);
    const ropes = [];
    rl.setPrompt('Enter the length of rope ' + (N + 1) + ': ');
    rl.question('', (ropeLength) => {
        ropes.push(parseInt(ropeLength));
        if(N > 1) {
            rl.setPrompt('Enter the length of rope ' + (N + 1) + ': ');
            rl.question('', (ropeLength) => {
                ropes.push(parseInt(ropeLength));
                if(N > 2) {
                    rl.setPrompt('Enter the length of rope ' + (N + 1) + ': ');
                    rl.question('', (ropeLength) => {
                        ropes.push(parseInt(ropeLength));
                        console.log('Minimum total cost: ', minCost(ropes));
                        process.exit(0);
                    });
                } else {
                    console.log('Minimum total cost: ', minCost(ropes));
                    process.exit(0);
                }
            });
        } else {
            console.log('Minimum total cost: ', minCost(ropes));
            process.exit(0);
        }
    });
});

function minCost(ropes) {
    ropes.sort((a, b) => a - b);
    let totalCost = 0;
    for(let i = 0; i < ropes.length - 1; i++) {
        totalCost += ropes[i];
        ropes[i + 1] += ropes[i];
        i++;
    }
    return totalCost;
}
This code takes the number of ropes and their lengths as input and calculates the minimum total cost of connecting all ropes. It first sorts the ropes in ascending order. Then, it iterates over the sorted ropes and calculates the total cost by adding the smallest rope length to the rest. The cost of connecting two ropes is the sum of their lengths.