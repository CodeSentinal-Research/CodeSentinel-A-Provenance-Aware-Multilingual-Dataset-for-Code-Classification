Sure, here is a simple JavaScript solution using Depth-First Search (DFS) to find the nearest common leaf:

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

class BinaryTree {
  constructor() {
    this.root = null;
  }

  add(data) {
    const newNode = new Node(data);

    if (!this.root) {
      this.root = newNode;
    } else {
      this.insertNode(this.root, newNode);
    }
  }

  insertNode(node, newNode) {
    if (newNode.data < node.data) {
      if (node.left) {
        this.insertNode(node.left, newNode);
      } else {
        node.left = newNode;
      }
    } else {
      if (node.right) {
        this.insertNode(node.right, newNode);
      } else {
        node.right = newNode;
      }
    }
  }

  findLeaves(node, leaves) {
    if (!node) return;

    if (!node.left && !node.right) {
      leaves.push(node.data);
    }

    this.findLeaves(node.left, leaves);
    this.findLeaves(node.right, leaves);
  }

  findCommonLeaves(node1, node2, commonLeaves) {
    if (!node1 || !node2) return;

    if (node1.data === node2.data) {
      if (!commonLeaves.includes(node1.data)) {
        commonLeaves.push(node1.data);
      }
    } else {
      this.findCommonLeaves(node1.left, node2.left, commonLeaves);
      this.findCommonLeaves(node1.right, node2.right, commonLeaves);
    }
  }

  findMinDistance(node1, node2, leaves) {
    if (!node1 || !node2) return;

    if (node1.data === node2.data) {
      this.findLeaves(node1, leaves);
    } else {
      this.findMinDistance(node1.left, node2.left, leaves);
      this.findMinDistance(node1.right, node2.right, leaves);
    }
  }
}

// usage
const binaryTree = new BinaryTree();

// add nodes
binaryTree.add(1);
binaryTree.add(2);
binaryTree.add(3);
binaryTree.add(4);
binaryTree.add(5);
binaryTree.add(6);
binaryTree.add(7);

// let's assume that these are the nodes we are looking for
let node1 = 6;
let node2 = 4;

let leaves1 = [];
let leaves2 = [];

binaryTree.findMinDistance(binaryTree.root, binaryTree.root, leaves1);
binaryTree.findMinDistance(binaryTree.root, binaryTree.root, leaves2);

binaryTree.findCommonLeaves(binaryTree.root, binaryTree.root, leaves1);
binaryTree.findCommonLeaves(binaryTree.root, binaryTree.root, leaves2);

let commonLeaves = [];

for (let leaf of leaves1) {
  if (leaves2.includes(leaf)) {
    commonLeaves.push(leaf);
  }
}

console.log('The nearest common leaf is:', commonLeaves[0]);

This script first creates a binary tree with the given nodes. Then, it finds the leaves of both nodes and finds the common leaves. Finally, it prints the first common leaf it finds.

Please note that this is a simple implementation and it assumes that the tree is a binary tree. If your tree is a different type of tree (e.g., a Binary Search Tree), you may need to adjust the `add` method and the `insertNode` method to match the tree structure.