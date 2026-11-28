let nodeIndex = 0;
let minDepth = Number.MAX_SAFE_INTEGER;
let minValue = Number.MAX_SAFE_INTEGER;
let minLeftmost = Number.MAX_SAFE_INTEGER;

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

  addNode(data) {
    const newNode = new Node(data);
    if (this.root === null) {
      this.root = newNode;
    } else {
      insertNode(this.root, newNode);
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

  findMinLeaf(node, depth) {
    if (node === null) {
      return;
    }
    this.findMinLeaf(node.left, depth + 1);
    if (node.left === null && node.right === null && depth < minDepth) {
      minDepth = depth;
      minValue = node.data;
      minLeftmost = node.data;
    } else if (node.left !== null && depth === minDepth && node.data < minValue) {
      minValue = node.data;
      minLeftmost = node.data;
    } else if (node.left !== null && depth === minDepth && node.data === minValue && node.data < minLeftmost) {
      minLeftmost = node.data;
    }
    this.findMinLeaf(node.right, depth + 1);
  }

  findMinLeafNode() {
    this.findMinLeaf(this.root, 0);
    return minValue;
  }
}

// You can use it as follows:
let tree = new BinaryTree();
let inputs = [1, 2, 3, 4, 5, 6, 7];
for (let i = 0; i < inputs.length; i++) {
  tree.addNode(inputs[i]);
}
console.log(tree.findMinLeafNode()); // Outputs: 4