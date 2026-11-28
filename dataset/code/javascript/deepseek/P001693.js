Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N;
rl.question('Enter the number of nodes: ', (N) => {
  let nodes = [];
  rl.close();
  rl.question('Enter the node values: ', (input) => {
    nodes = input.split(' ').map(Number);
    const tree = makeTree(nodes, 0);
    console.log(longestUnivaluePath(tree));
  });
});

function makeTree(nodes, index) {
  if (index < nodes.length && nodes[index] !== undefined) {
    const node = new TreeNode(nodes[index]);
    node.left = makeTree(nodes, 2 * index + 1);
    node.right = makeTree(nodes, 2 * index + 2);
    return node;
  }
  return null;
}

class TreeNode {
  constructor(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function longestUnivaluePath(root) {
  if (root === null) {
    return 0;
  }
  let[] path = [0];
  findPath(root, path);
  return path[0];
}

function findPath(node, path) {
  if (node === null) {
    return 0;
  }
  let leftPath = findPath(node.left, path);
  let rightPath = findPath(node.right, path);
  let leftUni = 0;
  let rightUni = 0;
  if (node.left !== null && node.left.val === node.val) {
    leftUni += leftPath + 1;
  }
  if (node.right !== null && node.right.val === node.val) {
    rightUni += rightPath + 1;
  }
  path[0] = Math.max(path[0], leftUni + rightUni);
  return Math.max(leftUni, rightUni);
}

In this code, we are first reading the number of nodes from the input and then reading the node values. The values are then used to create the binary tree. The longest univalue path is found and the result is printed.