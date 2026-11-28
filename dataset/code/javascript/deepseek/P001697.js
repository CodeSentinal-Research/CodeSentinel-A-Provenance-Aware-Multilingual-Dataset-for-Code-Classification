Here is the JavaScript code for the problem:

const fs = require('fs');
const readline = require('readline');

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
    const node = new Node(data);

    if (!this.root) {
      this.root = node;
    } else {
      let current = this.root;
      while (current) {
        if (node.data < current.data) {
          if (!current.left) {
            current.left = node;
            break;
          }
          current = current.left;
        } else {
          if (!current.right) {
            current.right = node;
            break;
          }
          current = current.right;
        }
      }
    }
  }

  isSubTree(node, x) {
    if (node == null) {
      return false;
    }

    if (this.isLeaf(node) && node.data == x) {
      return true;
    }

    return this.isSubTree(node.left, x) || this.isSubTree(node.right, x);
  }

  isLeaf(node) {
    if (node != null && node.left == null && node.right == null) {
      return true;
    }

    return false;
  }

  prune(root) {
    if (root == null) {
      return true;
    }

    if (this.isSubTree(root, 1) == false) {
      return false;
    }

    return this.prune(root.left) && this.prune(root.right);
  }

  createTree() {
    const lines = [];
    readline.createInterface({
      input: process.stdin
    }).on('line', (line) => {
      lines.push(line);
      if (lines.length == 2) {
        const data = lines[0].split(' ').map(Number);
        const tree = new BinaryTree();
        data.forEach((d) => {
          tree.insert(d);
        });

        this.root = tree.root;
        lines = [];
      }
    }).on('close', () => {
      const data = lines[0].split(' ').map(Number);
      const tree = new BinaryTree();
      data.forEach((d) => {
        tree.insert(d);
      });

      this.root = tree.root;
      console.log(this.prune(this.root));
    });
  }
}

new BinaryTree().createTree();

This code reads the input from the standard input and creates a binary tree for each test case. The `createTree` function is where the actual binary tree is created. The `prune` function is where the pruning of the binary tree is done. The `isSubTree` function is used to check if a subtree is present in the binary tree. The `isLeaf` function is used to check if a node is a leaf node. The `insert` function is used to insert a new node into the binary tree.