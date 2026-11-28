Here is the JavaScript code for the problem.

let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
input = input.trim().split('\n');
let N = Number(input[0]);
let tree = JSON.parse(input[1]);

function isSumTree(node, min = Number.MIN_SAFE_INTEGER, max = Number.MAX_SAFE_INTEGER) {
    if (node === null) {
        return true;
    }
    if (node.val < min || node.val > max) {
        return false;
    }
    if (isSumTree(node.left, min, node.val - 1) && isSumTree(node.right, node.val + 1, max)) {
        return true;
    }
    return false;
}

console.log(isSumTree(tree) ? 'YES' : 'NO');

This code reads the input file `input.txt` and parses the binary tree from the first line. Then it calls the `isSumTree` function with the root node of the tree as the argument.

The `isSumTree` function checks if a binary tree is a sum tree by recursively checking if each non-leaf node's value is equal to the sum of the node's value and its left and right subtrees. If the tree is a sum tree, the function returns `true`, otherwise it returns `false`.

The code uses a depth-first search (DFS) approach to traverse the tree. It starts from the root node and recursively checks if each non-leaf node's value is greater than or equal to its left subtree's value and less than or equal to its right subtree's value.

Finally, it prints `YES` if the tree is a sum tree, otherwise it prints `NO`.