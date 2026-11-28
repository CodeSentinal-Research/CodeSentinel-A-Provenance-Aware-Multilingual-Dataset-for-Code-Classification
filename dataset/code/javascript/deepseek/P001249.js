function connect_ropes(inputs) {
    let n = inputs[0];
    let lengths = inputs[1].map(Number);

    let totalCost = 0;

    // Prioritizing short ropes
    lengths.sort((a, b) => a - b);

    while (lengths.length > 1) {
        let smallestRope = lengths.shift();
        let nextSmallestRope = lengths.shift();

        let sumOfRopes = smallestRope + nextSmallestRope;
        totalCost += sumOfRopes;

        lengths.unshift(sumOfRopes); // Push back to sorted array
        lengths.sort((a, b) => a - b); // Sort again
    }

    return totalCost;
}

let inputs = require('fs').readFileSync('./input.txt', 'utf8').split('\n');
console.log(connect_ropes(inputs));