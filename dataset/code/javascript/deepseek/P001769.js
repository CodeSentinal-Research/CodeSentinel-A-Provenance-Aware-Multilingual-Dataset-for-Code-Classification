// Node structure
class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

// Binary Tree
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

  findMinimumValueAtEachLevel() {
    if (!this.root) {
      console.log("Tree is empty");
      return;
    }

    let currentLevel = [this.root];
    let nextLevel = [];

    while (currentLevel.length > 0) {
      let minValue = currentLevel[0].data;
      currentLevel.forEach(node => {
        if (node.data < minValue) {
          minValue = node.data;
        }

        if (node.left) {
          nextLevel.push(node.left);
        }

        if (node.right) {
          nextLevel.push(node.right);
        }
      });

      console.log(`Minimum value at level ${currentLevel.length}: ${minValue}`);
      currentLevel = nextLevel;
      nextLevel = [];
    }
  }
}

// Driver code
let tree = new BinaryTree();

let nodes = [3, 9, 20, 4, 1, 11, 1, 4];

nodes.forEach(node => tree.add(node));

tree.findMinimumValueAtEachLevel();