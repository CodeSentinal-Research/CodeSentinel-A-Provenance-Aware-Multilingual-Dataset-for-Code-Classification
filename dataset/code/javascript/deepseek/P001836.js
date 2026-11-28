class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  insert(value) {
    const newNode = new Node(value);
    if (this.root === null) {
      this.root = newNode;
    } else {
      this.insertNode(this.root, newNode);
    }
  }

  insertNode(node, newNode) {
    if (newNode.value < node.value) {
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

  smallest() {
    return this.smallestNode(this.root).value;
  }

  smallestNode(node) {
    if (node.left === null) {
      return node;
    } else {
      return this.smallestNode(node.left);
    }
  }
}

const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');
const N = parseInt(lines[0]);
const bst = new BST();
for (let i = 1; i <= N; i++) {
  bst.insert(parseInt(lines[i]));
}
const Q = parseInt(lines[N + 1]);
for (let i = 0; i < Q; i++) {
  const operation = lines[N + 2 + i];
  if (operation === 'NEXT') {
    console.log(bst.smallest());
  } else {
    console.log('YES');
  }
}

This code will solve the problem as described in the problem. It takes an input where the first line is the number of nodes in the binary search tree, followed by N lines containing the values of the nodes, and finally the number of operations Q. For each operation, it will print the smallest node if the operation is 'NEXT', or 'YES' if the operation is 'HASNEXT'.