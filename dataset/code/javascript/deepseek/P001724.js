Here's the JavaScript code to solve the problem:

process.stdin.resume();
process.stdin.setEncoding('ascii');

var n = parseInt(process.stdin.read(), 10),
    nodes = process.stdin.read().split(' ').map(Number),
    binaryTree = {}, tree = {};

for (var i = 0; i < n; i++) {
  binaryTree[i] = [nodes[i * 2], nodes[i * 2 + 1]];
}

function findMin(node, sum) {
  if (tree[node]) {
    return tree[node];
  }
  sum += nodes[node];
  if (nodes[node * 2 + 1] === undefined && nodes[node * 2 + 2] === undefined) {
    tree[node] = sum;
  } else {
    tree[node] = Math.min(findMin(node * 2, sum), findMin(node * 2 + 1, sum))
  }
  return tree[node];
}

console.log(Math.min.apply(Math, [...new Set(binaryTree.map(findMin))]));

This JavaScript code reads the input from stdin. It first reads the number of nodes, then reads the node values. Then, it builds a binary tree structure from the node values. 

The `findMin` function is a recursive function that calculates the sum of the minimum sum path from the root to a leaf in the binary tree.

Finally, it logs the minimum sum from all paths in the binary tree.