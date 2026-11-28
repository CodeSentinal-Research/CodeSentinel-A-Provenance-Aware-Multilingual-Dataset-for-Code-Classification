Here is a solution in JavaScript. This solution uses the concept of recursive function calls to check if both trees have the same values and same structure.

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

function isIdentical(root1, root2) {
  if (root1 === null && root2 === null) {
    return true;
  }
  if (root1 === null || root2 === null) {
    return false;
  }
  return (
    root1.data === root2.data &&
    isIdentical(root1.left, root2.left) &&
    isIdentical(root1.right, root2.right)
  );
}

function buildTree(lines) {
  const values = lines.shift();
  if (values === 'X') {
    return null;
  }
  const node = new Node(values);
  node.left = buildTree(lines);
  node.right = buildTree(lines);
  return node;
}

let input = [
  [3, 5, 1, 'X', 'X', 2, 'X'],
  5,
  [5, 1, 2, 'X', 'X', 'X', 'X'],
];

let tree1 = buildTree(input);
input = [
  [3, 5, 1, 'X', 'X', 2, 'X'],
  5,
  [5, 1, 2, 'X', 'X', 'X', 'X'],
];
let tree2 = buildTree(input);

console.log(isIdentical(tree1, tree2) ? 'YES' : 'NO');

This script uses recursive approach to compare the trees. For every node in the trees, it compares the data, then recursively compares the left and right subtrees. If all nodes match, it returns true; otherwise, it returns false.

Please note that this code expects input to be a list of values. Each value is a node data. 'X' is used to denote a null node. For example, a tree [3, 5, 1, 'X', 'X', 2, 'X'] would be represented as [new Node(3), new Node(5), new Node(1), new Node('X'), new Node('X'), new Node(2), new Node('X')].