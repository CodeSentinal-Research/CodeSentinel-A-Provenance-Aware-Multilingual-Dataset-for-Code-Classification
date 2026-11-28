Here is a JavaScript solution for the problem:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class Tree {
  constructor() {
    this.root = null;
  }

  add(data) {
    const newNode = new Node(data);

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

  leftView() {
    let max_level = -1;
    this.leftViewUtil(this.root, 0, res);
    return res;
  }

  leftViewUtil(node, level, res) {
    if (node === null)
      return;

    let key = node.data;

    if (max_level < level) {
      res[res.length] = key;
      max_level = level;
    }

    this.leftViewUtil(node.left, level + 1, res);
    this.leftViewUtil(node.right, level + 1, res);
  }
}

let t = new Tree();
let arr = process.argv[2];
arr = arr.split(/\s+/);
arr.shift();
for (let i = 0; i < arr.length; i++) {
  t.add(arr[i]);
}
console.log(t.leftView());

This program first creates a binary tree and then prints the left view of the binary tree. It assumes that the binary tree is binary search tree. If the tree is not a BST, the algorithm may not work as expected. The left view of a binary tree is the node of the leftmost leaf node in the tree's left subtree.

You can run this program by passing the input as a command line argument. For example, if you run this program, you can pass the input as follows:

node script.js 1 2 3 4 5 6 7 8 9 10

The script will add the numbers to the binary tree and then print the left view.