Here is the JavaScript code for the problem.

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let N = parseInt(lines.shift());

let pairs = [];
lines.forEach(line => {
    pairs.push(line.split(' ').map(x => parseInt(x)));
});

pairs.sort((a, b) => a[1] - b[1]);

let maxChain = 1;
let currentChain = 1;

for (let i = 1; i < N; i++) {
    if (pairs[i][0] > pairs[i-1][1]) {
        currentChain++;
        maxChain = Math.max(maxChain, currentChain);
    } else {
        currentChain = 1;
    }
}

console.log(maxChain);

This code reads the number of pairs from the standard input and then reads the pairs themselves. The pairs are stored in an array of arrays (pairs), where each sub-array contains two elements (a and b).

The pairs are then sorted by the second element (b) in ascending order.

A loop iterates through the sorted pairs, and for each pair, it checks if the first element (a) is greater than the second element (b) of the previous pair. If it is, it increments the chain count and updates the maximum chain length if necessary. If not, it resets the chain count.

Finally, the maximum chain length is printed to the standard output.