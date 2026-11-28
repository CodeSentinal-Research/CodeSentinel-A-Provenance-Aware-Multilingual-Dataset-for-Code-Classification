Here is the JavaScript solution for the given problem:

let count = 0;

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class BinaryTree {
  constructor() {
    this.root = null;
  }

  insert(data) {
    let newNode = new Node(data);
    if (this.root === null) {
      this.root = newNode;
    } else {
      this.insertNode(this.root, newNode);
    }
  }

  insertNode(node, newNode) {
    if (newNode.data < node.data) {
      if (node.left === null) {
        node.left = newNode;
      } else {
        this.insertNode(node.left, newNode);
      }
    } else {
      if (node.right === null) {
        node.right = newNode;
      } else {
        this.insertNode(node.right, newNode);
      }
    }
  }

  countFullNodes() {
    this.countFullNodesRecursive(this.root);
    return count;
  }

  countFullNodesRecursive(node) {
    if (node === null) {
      return;
    }
    if (node.left !== null && node.right !== null) {
      count++;
    }
    this.countFullNodesRecursive(node.left);
    this.countFullNodesRecursive(node.right);
  }
}

function main() {
  let tree = new BinaryTree();
  let inputs = process.argv.slice(2).map(Number);
  inputs.forEach(input => tree.insert(input));
  console.log(tree.countFullNodes());
}

main();

This program first inserts the numbers from the command line arguments into a binary tree. Then, it calls the `countFullNodes` method on the binary tree to count the number of full nodes in the tree.

Note: This code assumes that the numbers are entered on the command line. The first argument should be the number of nodes, followed by the data of the nodes. For example, if you run `node countFullNodes.js 5 1 2 3 4 5`, it will create a binary tree with 5 nodes, and count the full nodes in it.