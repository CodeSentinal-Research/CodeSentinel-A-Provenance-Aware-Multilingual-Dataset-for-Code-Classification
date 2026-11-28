Here is the JavaScript code:

let inputs = require('fs').readFileSync('input.txt', 'utf8').split('\n');
let output = '';

class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function processInput(input, index, count, max) {
    let node = new Node(input[index++]);
    if (index < count) {
        node.left = new Node(input[index++]);
        if (index < count) {
            node.right = new Node(input[index++]);
        }
    }
    return node;
}

let root = processInput(inputs[0].split(' '), 0, inputs.length, Number(inputs[0]));

function maxSumPath(node, max) {
    if (!node) {
        return -Infinity;
    }
    max = Math.max(max, node.value);
    let left = maxSumPath(node.left, max);
    let right = maxSumPath(node.right, max);
    return Math.max(max, node.value + Math.max(left, right));
}

output = maxSumPath(root, -Infinity);

console.log(output);

This code creates a binary tree from the input data and calculates the maximum sum of a path from the root to a leaf.