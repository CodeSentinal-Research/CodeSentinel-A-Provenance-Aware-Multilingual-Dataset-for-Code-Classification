Here is a simple JavaScript solution for the problem:

class Node {
  constructor(key) {
    this.key = key;
    this.left = null;
    this.right = null;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  insert(key) {
    const node = new Node(key);

    if (this.root === null) {
      this.root = node;
    } else {
      this.insertNode(this.root, node);
    }
  }

  insertNode(node, newNode) {
    if (newNode.key < node.key) {
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

  findRange(node, low, high) {
    if (node === null) return;

    if (node.key > low)
      this.findRange(node.left, low, high);

    if (node.key >= low && node.key <= high)
      console.log(node.key);

    if (node.key < high)
      this.findRange(node.right, low, high);
  }
}

// Test the solution
const bst = new BST();

// Insert keys into the BST
bst.insert(50);
bst.insert(30);
bst.insert(20);
bst.insert(40);
bst.insert(70);
bst.insert(60);
bst.insert(80);

// Find and print all keys within the range 20 to 80
bst.findRange(bst.root, 20, 80);

In this code, we first define a `Node` class that will be used to create new nodes in the BST. Each node has a `key`, and references to its left and right children.

The `BST` class is the main class that holds the root of the tree. It has methods for inserting nodes and finding all keys within a given range. The `findRange` method is a recursive function that traverses the BST, printing out all keys that are within the specified range.

Finally, we test this code by inserting several keys into a BST, and then finding and printing all keys within the range 20 to 80.