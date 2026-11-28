// Create a node class
class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

// Create a binary tree
class BinaryTree {
  constructor() {
    this.root = null;
  }

  // Insert node into the binary tree
  insertNode(data) {
    const newNode = new Node(data);

    if (this.root === null) {
      this.root = newNode;
    } else {
      this.insertNodeHelper(this.root, newNode);
    }
  }

  // Insert node helper function
  insertNodeHelper(node, newNode) {
    if (newNode.data < node.data) {
      if (node.left === null) {
        node.left = newNode;
      } else {
        this.insertNodeHelper(node.left, newNode);
      }
    } else {
      if (node.right === null) {
        node.right = newNode;
      } else {
        this.insertNodeHelper(node.right, newNode);
      }
    }
  }
}

// Find lowest common ancestor
function findLCA(root, n1, n2) {
  while (root != null) {
    if (root.data > n1 && root.data > n2) {
      root = root.left;
    } else if (root.data < n1 && root.data < n2) {
      root = root.right;
    } else {
      break;
    }
  }
  return root.data;
}

// Test
const binaryTree = new BinaryTree();
binaryTree.insertNode(50);
binaryTree.insertNode(30);
binaryTree.insertNode(20);
binaryTree.insertNode(40);
binaryTree.insertNode(70);
binaryTree.insertNode(60);
binaryTree.insertNode(80);

console.log(findLCA(binaryTree.root, 40, 70));  // Output: 50

This JavaScript code first creates a binary tree using the provided input. Then, it calls the `findLCA` function to find the lowest common ancestor of the two nodes with values 40 and 70. The `findLCA` function uses a while loop to traverse the binary tree until it finds the lowest common ancestor. Once it finds the lowest common ancestor, it returns the value of the lowest common ancestor. The input for the binary tree is hardcoded in the test section.