class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  insert(data) {
    const node = this.root;
    if (node === null) {
      this.root = new Node(data);
      return;
    } else {
      let newNode;

      if (data < node.data) {
        if (node.left === null) {
          node.left = new Node(data);
          return;
        } else {
          node = node.left;
        }
      } else {
        if (node.right === null) {
          node.right = new Node(data);
          return;
        } else {
          node = node.right;
        }
      }
    }
  }

  findFloor(node, data) {
    if (node === null) {
      return null;
    }

    if (data < node.data) {
      return this.findFloor(node.left, data);
    } else if (data > node.data) {
      return this.findFloor(node.right, data);
    } else {
      return node.data;
    }
  }
}

let input = require('fs').readFileSync('stdin', 'utf8');
const lines = input.split('\n');
const N = parseInt(lines[0]);
const keys = lines[1].split(' ').map(Number);
const X = parseInt(lines[lines.length - 1]);

const bst = new BST();

for (let i = 0; i < N; i++) {
  bst.insert(keys[i]);
}

console.log(bst.findFloor(bst.root, X));

This code firstly constructs a binary search tree (BST) by inserting all the keys provided in the input. Then, it calls the `findFloor` method, which uses a recursive approach to find the largest key in the BST that is less than or equal to X. If no such key exists, it will return `null`.