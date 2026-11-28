Here's a basic implementation of a Binary Search Tree (BST) using the given keys and their search frequencies:

class Node {
  constructor(key, freq) {
    this.key = key;
    this.freq = freq;
    this.left = null;
    this.right = null;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  insert(key, freq) {
    const newNode = new Node(key, freq);

    if (this.root === null) {
      this.root = newNode;
    } else {
      let current = this.root;
      while (current !== null) {
        if (newNode.freq < current.freq) {
          if (current.left === null) {
            current.left = newNode;
            break;
          }
          current = current.left;
        } else {
          if (current.right === null) {
            current.right = newNode;
            break;
          }
          current = current.right;
        }
      }
    }
  }

  inOrder() {
    if (this.root === null) {
      return null;
    }
    let current = this.root;
    let stack = [];
    while (current || stack.length > 0) {
      while (current) {
        stack.push(current);
        current = current.left;
      }
      current = stack.pop();
      console.log(current.key);
      current = current.right;
    }
  }
}

// Example usage:
let keys = [3, 1, 4, 2, 5]; // given keys
let frequencies = [2, 1, 3, 2, 1]; // given frequencies
let bst = new BST();

for (let i = 0; i < keys.length; i++) {
  bst.insert(keys[i], frequencies[i]);
}

bst.inOrder();

This code first creates a Node class to define a node in the BST. The BST class has an insert method to insert a new node into the BST and an inOrder method to print the keys of the BST in order.

The example usage at the end creates a new BST and inserts the given keys and frequencies into the BST. Finally, it calls the inOrder method to print the keys of the BST in order.