Here is the JavaScript code for the problem:

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

  add(value) {
    let newNode = new Node(value);
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

  inOrder(root, callback) {
    if (root !== null) {
      this.inOrder(root.left, callback);
      callback(root.value);
      this.inOrder(root.right, callback);
    }
  }

  findThreeSum(k) {
    this.inOrder(this.root, (value) => {
      if (k - value >= 0 && this.findPair(this.root, k - value, value)) {
        console.log('YES');
        return;
      }
    });
  }

  findPair(root, k, excludeValue) {
    let pairExists = false;
    this.inOrder(root, (value) => {
      if (excludeValue + value === k && value !== excludeValue) {
        pairExists = true;
      }
    });
    return pairExists;
  }
}

let input = require('fs').readFileSync('input.txt', 'utf8').split('\n').map(Number);
let k = input[input.length - 1];
input = input.slice(0, input.length - 1);

let bst = new BST();

input.forEach((value) => {
  bst.add(value);
});

bst.findThreeSum(k);

This code reads the input from a file named 'input.txt', splits the file into lines, converts each line to a number, and then creates a Binary Search Tree (BST) from the numbers. It then calls the `findThreeSum` function of the BST to check if there exists three nodes in the BST whose sum to the given value is `k`.