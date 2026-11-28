Here's the JavaScript code to solve the problem:

let lines = require('fs').readFileSync('stdin', 'utf8');
const N = +lines[0];
let tree = new Array(N).fill(null).map((_, i) => {
    const line = lines[i + 1].split(' ');
    return {left: +line[0], right: +line[1]};
});

function isFullTree(node, min = null, max = null) {
    if (node === null) {
        return true;
    }

    if ((min !== null && node.left !== null && node.left < min) ||
        (max !== null && node.left !== null && node.left > max) ||
        (min !== null && node.right !== null && node.right < min) ||
        (max !== null && node.right !== null && node.right > max)) {
        return false;
    }

    return isFullTree(node.left, min, node.left ? node.left : min) &&
        isFullTree(node.right, node.right ? node.right : max, min);
}

console.log(isFullTree(tree[0]) ? 'YES' : 'NO');

This JavaScript code uses a recursive approach to check whether a binary tree is full. It starts by reading the number of nodes (N) from the standard input. Then, for each node, it reads the left and right child of the node. If the tree is full, it will print 'YES'; otherwise, it will print 'NO'.