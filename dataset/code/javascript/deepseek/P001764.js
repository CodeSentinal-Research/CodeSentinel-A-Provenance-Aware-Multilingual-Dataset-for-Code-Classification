Here is the JavaScript code for the problem:

const fs = require('fs');
process.stdin.resume();
process.stdin.setEncoding('ascii');

let binaryTreeInput = process.stdin.read();
binaryTreeInput = binaryTreeInput.toString().split('\n');

let N = parseInt(binaryTreeInput.shift());

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

let binaryTree = new Map();

binaryTreeInput.forEach((line) => {
    let [nodeValue, leftValue, rightValue] = line.split(' ').map(Number);
    let node = new Node(nodeValue);
    if (leftValue !== -1) node.left = new Node(leftValue);
    if (rightValue !== -1) node.right = new Node(rightValue);
    binaryTree.set(nodeValue, node);
});

let res = 0;

function dfs(node) {
    if (node === null) {
        return 0;
    }
    let left = dfs(node.left);
    let right = dfs(node.right);
    if (node.left && node.left.data === node.data && left > 0) {
        left++;
    }
    if (node.right && node.right.data === node.data && right > 0) {
        right++;
    }
    res = Math.max(res, left + right);
    return Math.max(left, right) + 1;
}

dfs(binaryTree.get(binaryTreeInput[0]));

console.log(res);

This code reads the input from standard input, constructs a binary tree based on the input, and then uses depth-first search (dfs) to find the size of the largest univalue subtree.

Please note that you need to provide the input data to the script in the format specified in the problem.