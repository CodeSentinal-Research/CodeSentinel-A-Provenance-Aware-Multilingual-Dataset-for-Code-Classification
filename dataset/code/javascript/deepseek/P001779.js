Here is the JavaScript code to solve the problem:

// Define the Node class
class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

// Define the Binary Tree class
class BinaryTree {
  constructor() {
    this.root = null;
  }

  // Add a node to the binary tree
  addNode(value) {
    const newNode = new Node(value);

    if (!this.root) {
      this.root = newNode;
    } else {
      this.insertNode(this.root, newNode);
    }
  }

  // Insert a node into the binary tree
  insertNode(node, newNode) {
    if (newNode.value < node.value) {
      if (node.left) {
        this.insertNode(node.left, newNode);
      } else {
        node.left = newNode;
      }
    } else {
      if (node.right) {
        this.insertNode(node.right, newNode);
      } else {
        node.right = newNode;
      }
    }
  }

  // Find the longest increasing path in the binary tree
  findLongestIncreasingPath() {
    if (!this.root) {
      return 0;
    }

    let maxPath = [0, 0]; // maxPath[0] is the max path, maxPath[1] is the length of the max path

    this.findPath(this.root, maxPath, 1);

    return maxPath[1];
  }

  // Find the longest increasing path in the binary tree recursively
  findPath(node, maxPath, length) {
    if (!node) {
      return;
    }

    let leftLength = length, rightLength = length;

    if (node.left) {
      this.findPath(node.left, maxPath, leftLength + 1, node.left.value);
    }

    if (node.right) {
      this.findPath(node.right, maxPath, rightLength + 1, node.right.value);
    }

    if (maxPath[0] < leftLength + rightLength + 1) {
      maxPath[0] = leftLength + rightLength + 1;
      maxPath[1] = leftLength + rightLength + 1;
    } else if (maxPath[0] === leftLength + rightLength + 1) {
      maxPath[1] = Math.max(maxPath[1], leftLength + rightLength + 1);
    }
  }
}

// Create the binary tree and add nodes
let binaryTree = new BinaryTree();
let nodes = Array.from(new Array(100000), () => Math.floor(Math.random() * 100000));
nodes.forEach(node => binaryTree.addNode(node));

// Get the longest increasing path
let longestIncreasingPath = binaryTree.findLongestIncreasingPath();

console.log(longestIncreasingPath);

This code first defines a `Node` class and a `BinaryTree` class. The `BinaryTree` class contains methods to add nodes to the binary tree and to find the longest increasing path in the binary tree. The `BinaryTree` class uses a depth-first search approach to find the longest increasing path in the binary tree.

Please note that the actual execution of the code may vary based on the input and the specific order of the node values. This code is just an example of how to solve the problem and does not include any error handling or input validation.