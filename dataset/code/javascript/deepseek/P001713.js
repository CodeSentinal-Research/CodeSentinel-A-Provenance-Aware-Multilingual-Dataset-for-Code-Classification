Here is the JavaScript code for the problem.

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

  removeHalfNodes() {
    this.root = this.removeHalfNodesRecursive(this.root);
  }

  removeHalfNodesRecursive(node) {
    if (node === null) {
      return null;
    }

    let child = node.left || node.right;

    if (child === null) {
      return node;
    }

    child = this.removeHalfNodesRecursive(child);

    if (child !== null) {
      child.left = node.left;
      child.right = node.right;
    }

    return child;
  }

  createBinaryTree(arr) {
    if (arr[0] === null) {
      return null;
    }

    let node = new Node(arr[0]);
    let root = node;
    let arrIndex = 1;

    while (arrIndex < arr.length) {
      let parent = arr[arrIndex++];
      let node = new Node(parent);

      if (parent !== null) {
        node.left = new Node(arr[arrIndex++]);
        node.right = new Node(arr[arrIndex++]);
      }

      if (parent === null) {
        root = node;
      }
    }

    return root;
  }

  printTree(node) {
    if (node === null) {
      return;
    }

    console.log(node.data);
    this.printTree(node.left);
    this.printTree(node.right);
  }
}

This code defines a BinaryTree class with methods to create a binary tree from an array, and print the tree. The removeHalfNodes method uses recursion to remove nodes with one child, and the printTree method prints the tree.

You can test this code with the following code:

let binaryTree = new BinaryTree();
let arr = [1, 2, 3, 4, 5, 6, 7];
binaryTree.root = binaryTree.createBinaryTree(arr);
binaryTree.removeHalfNodes();
binaryTree.printTree(binaryTree.root);

This will print the binary tree after removing half nodes.