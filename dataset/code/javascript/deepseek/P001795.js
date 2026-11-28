Here is the JavaScript code for the problem:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  insert(data) {
    const node = new Node(data);
    if (this.root === null) {
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

  inOrder() {
    if (this.root == null) {
      return null;
    } else {
      let current = this.root;
      let stack = [];
      while (current || stack.length) {
        while (current) {
          stack.push(current);
          current = current.left;
        }
        current = stack.pop();
        console.log(current.data);
        current = current.right;
      }
    }
  }
}

let tree = new BinarySearchTree();
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

arr.forEach(item => {
  tree.insert(item);
});

tree.inOrder();

In this code, a binary search tree (BST) is created with a sorted array of integers. The BST is constructed by inserting each item in the array into the BST in order. The BST is then traversed in-order to print the items.