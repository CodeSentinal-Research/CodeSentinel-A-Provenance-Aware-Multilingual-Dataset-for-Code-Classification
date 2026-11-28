Here is a JavaScript solution for your problem. We first define a Node class, then define a function to calculate the sum of a node's descendants. Finally, we use this function to convert the tree.

class Node {
  constructor(value, left = null, right = null) {
    this.value = value;
    this.left = left;
    this.right = right;
  }
}

function sumDescendants(node) {
  if (node === null) {
    return 0;
  }

  let leftSum = sumDescendants(node.left);
  let rightSum = sumDescendants(node.right);

  node.value = leftSum + rightSum + node.value;

  return node.value;
}

function constructTree(nodes, tree, i) {
  if (i < nodes.length) {
    if (nodes[i] !== null) {
      let node = new Node(nodes[i]);
      tree[i] = node;
      tree[i].left = constructTree(nodes, tree, 2 * i + 1);
      tree[i].right = constructTree(nodes, tree, 2 * i + 2);
    }
    return i;
  }
}

function printTree(tree, i, depth) {
  if (i === -1) return;
  printTree(tree, tree[i].left, depth + 1);
  console.log('  '.repeat(depth) + tree[i].value);
  printTree(tree, tree[i].right, depth + 1);
}

let nodes = process.argv[2].split(/\D+/).filter(s => s);
let tree = [];
constructTree(nodes, tree, 0);
sumDescendants(tree[0]);
printTree(tree, 0, 0);

This script reads the node values from the command line arguments, constructs the tree, and then prints the transformed tree. The input is expected to be provided in the form of space-separated numbers, where nulls represent null nodes.

Please note that this code assumes that the input tree is a complete binary tree with the value of each node in the array. If the input tree is not a complete binary tree, the sum of the node values will not be the sum of its descendants and the tree will not be transformed correctly.