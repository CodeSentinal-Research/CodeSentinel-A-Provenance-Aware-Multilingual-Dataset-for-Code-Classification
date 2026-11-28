Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(line.split(' '));
}).on('close', function() {
    const [N, sequence] = inputs[0];
    const keys = sequence.map(Number);

    let maxHeight = 0;
    let left = 0;
    let right = keys.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const currentHeight = Math.max(
            binarySearchTreeHeight(keys, left, mid),
            binarySearchTreeHeight(keys, mid + 1, right)
        );
        maxHeight = Math.max(maxHeight, currentHeight);
        left = mid + 1;
        right = mid - 1;
    }

    console.log(maxHeight);

    rl.close();
});

function binarySearchTreeHeight(arr, start, end) {
    if (start > end) return 0;

    let maxHeight = 0;
    let left = start;
    let right = end;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const currentHeight = Math.max(
            binarySearchTreeHeight(arr, left, mid),
            binarySearchTreeHeight(arr, mid + 1, right)
        );
        maxHeight = Math.max(maxHeight, currentHeight);
        left = mid + 1;
        right = mid - 1;
    }

    return maxHeight + 1;
}

This code reads the inputs from the standard input and calculates the height of the resulting Binary Search Tree. It uses a binary search algorithm to find the maximum height of the BST. The maximum height is maintained in a variable and updated with each iteration of the binary search.

Please note that you need to run this script in an environment that supports Node.js, like the Node.js runtime. Also, the input is assumed to be a list of distinct keys, and the keys are provided in the same order as they were inserted into the BST.