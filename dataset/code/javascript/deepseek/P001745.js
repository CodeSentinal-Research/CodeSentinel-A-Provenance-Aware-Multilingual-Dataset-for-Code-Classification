Here is the JavaScript code for the given problem. This code assumes that the input is a binary tree. The structure of the tree is defined by an array where each element is a node and its children are represented as indices.

let tree;
let heights = [];

function processNode(node, height = 0) {
  if (tree[node] === undefined) {
    // This node is not in the tree
    heights[node] = height;
    return;
  }

  // Process children nodes
  processNode(tree[node][0], height + 1);
  processNode(tree[node][1], height + 1);
}

function solve(N, treeInput) {
  tree = {};
  heights = [];

  // Construct tree from input
  for (let i = 0; i < N; i++) {
    let [node, left, right] = treeInput[i].split(' ');
    tree[Number(node)] = [Number(left), Number(right)];
  }

  // Process root node
  processNode(1);

  // Print heights of all nodes
  for (let i = 1; i <= N; i++) {
    console.log(heights[i]);
  }
}

To use this code, you would call the `solve` function with the number of nodes in the tree and an array of tree nodes. The tree nodes would be in the format `[parent, leftChild, rightChild]`.

Here's an example of how you might use the code:

solve(7, [
  '1 2 3',
  '2 4 5',
  '3 6 7',
  '1 3 4',
  '2 5 6',
  '3 7 8',
  '4 8 9',
]);

This will print the heights of the nodes from 1 to 7.