Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let nodes = [];

rl.on('line', (line) => {
    nodes.push(parseInt(line));
    if (nodes.length === nodes.length ** 2) {
        rl.close();
    }
});

rl.on('close', () => {
    const [root] = nodes;
    const [left, right] = nodes.slice(1);
    const tree = {val: root, left: left === -1 ? null : {val: left, left: null, right: null}, right: right === -1 ? null : {val: right, left: null, right: null}};
    console.log(findLargestBST(tree).size);
});

function findLargestBST(node) {
    if (node === null) {
        return { size: 0, min: Infinity, max: -Infinity, isBST: true };
    }

    const left = findLargestBST(node.left);
    const right = findLargestBST(node.right);

    if (!left.isBST || !right.isBST || node.val <= left.max || node.val >= right.min) {
        return { size: Math.max(left.size, right.size), min: Math.min(node.val, left.min), max: Math.max(node.val, right.max), isBST: false };
    }

    return {
        size: Math.max(left.size, right.size, node.val - left.min, right.max - node.val),
        min: Math.min(node.val, left.min),
        max: Math.max(node.val, right.max),
        isBST: true
    };
}

This code reads the binary tree from the input, constructs the tree, and then calls the `findLargestBST` function. The `findLargestBST` function recursively checks each node in the tree. It returns an object with the size of the largest BST, the minimum value of the BST, the maximum value of the BST, and whether the BST is a binary search tree.