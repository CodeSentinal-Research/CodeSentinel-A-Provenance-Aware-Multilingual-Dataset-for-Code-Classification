Here is a JavaScript solution for the problem:

let binaryTreeInput = require('fs').readFileSync('input.txt', 'utf8');
let [N, ...tree] = binaryTreeInput.split('\n');
N = Number(N);

let leafNodeCount = 0;

function countLeafNodes(node) {
    if (!node) {
        return 0;
    }

    if (!node.left && !node.right) {
        leafNodeCount++;
        return 1;
    }

    return countLeafNodes(node.left) + countLeafNodes(node.right);
}

console.log(countLeafNodes(tree[0]));

This solution uses a recursive approach to count the leaf nodes in the binary tree. The `countLeafNodes` function is called with the root of the tree as an argument. If the node is `null`, it returns 0. If the node is a leaf node (i.e., it has no left or right children), it increments the leaf node count and returns 1. Otherwise, it recursively counts the leaf nodes in the left and right children and returns the total.