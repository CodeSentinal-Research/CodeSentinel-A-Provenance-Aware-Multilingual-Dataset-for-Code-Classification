Here is a JavaScript solution using recursion:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class BST {
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

  findLargestKeySmaller(node, x) {
    if (node === null) {
      return null;
    }
    if (node.data < x && node.right !== null) {
      return this.findLargestKeySmaller(node.right, x);
    } else if (node.data < x) {
      return node.data;
    } else if (node.right === null) {
      return node.data;
    } else {
      return this.findLargestKeySmaller(node.left, x);
    }
  }
}

This script creates a binary search tree and provides a method to find the largest key that is smaller than a given value. The binary search tree is constructed by inserting values into the tree one at a time.

The insert method is used to insert a new node into the tree. The insertNode method is a recursive method that inserts a new node into the binary search tree. The findLargestKeySmaller method is a recursive method that finds the largest key that is smaller than a given value. It starts at the root and compares the value of the current node to the given value. If the current node's value is less than the given value, it moves to the right child of the current node. If the current node's value is greater than the given value, it moves to the left child. If the current node's value is less than the given value and there is no left child, the current node's value is the largest key that is smaller than the given value. If the current node's value is greater than the given value and there is no right child, the current node's value is the largest key that is smaller than the given value. If the current node's value is greater than the given value and there is a right child, it starts a new search from the left child of the current node.