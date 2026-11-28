Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = [];
rl.on('line', (line) => {
    testCases.push(parseInt(line));
});
rl.on('close', () => {
    const [N, D] = testCases;
    const weights = [];
    rl.setPrompt('Enter weights:');
    rl.on('line', (line) => {
        weights.push(parseInt(line));
        if (weights.length === N) {
            console.log(findMinCapacity(weights, D));
            rl.close();
        }
    });
});

function findMinCapacity(weights, D) {
    weights.sort((a, b) => a - b);
    let l = 0, r = weights[N - 1];
    while (l < r) {
        const mid = Math.floor((l + r) / 2);
        if (canShip(weights, D, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

function canShip(weights, D, capacity) {
    let d = 1, current = capacity;
    for (let i = 0; i < weights.length; i++) {
        if (weights[i] > current) {
            current = capacity;
            d++;
        }
        current -= weights[i];
    }
    return d <= D;
}

This code uses binary search to find the least weight capacity required to ship all packages within D days. It sorts the weights in ascending order, then uses binary search to find the least weight capacity that can ship all packages within D days. The binary search is done in a way that it halves the search space with each iteration. If the current capacity can ship all packages within D days, it halves the range from `l` to `mid`, otherwise it halves the range from `mid + 1` to `r`. The time complexity of this code is O(N log N) due to the sorting, and the binary search itself is O(log N).