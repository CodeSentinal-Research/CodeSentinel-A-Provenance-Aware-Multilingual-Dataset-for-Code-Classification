const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs.push(Number(line));

    if(inputs.length === 3) {
        const [N, arr, key] = inputs;
        const counts = arr.reduce((acc, num) => ({ ...acc, [num]: (acc[num] || 0) + 1 }), {});
        const sortedCounts = Object.entries(counts)
            .sort((a, b) => b[1] - a[1])
            .find(([num]) => num === key);
        if (sortedCounts) {
            console.log(sortedCounts[0]);
        } else {
            console.log('No solution');
        }
        rl.close();
    }
});