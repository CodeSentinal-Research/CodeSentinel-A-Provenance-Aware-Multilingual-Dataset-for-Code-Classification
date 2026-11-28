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
      let current = this.root;
      while (current) {
        if (newNode.data < current.data) {
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

  findInorderPredecessor(root, target) {
    if (!root) return null;
    let pred = null;
    while (root) {
      if (root.data < target) {
        pred = root;
        root = root.left;
      } else if (root.data > target) {
        root = root.right;
      } else {
        break;
      }
    }
    return pred ? pred.data : null;
  }
}

let input = [
  5,
  2, 8,
  1, 4,
  7, 10
];

let bst = new BST();
for (let i = 0; i < input.length; i++) {
  bst.insert(input[i]);
}

console.log(bst.findInorderPredecessor(bst.root, 10)); // 7
console.log(bst.findInorderPredecessor(bst.root, 1)); // 2
console.log(bst.findInorderPredecessor(bst.root, 2)); // 4
console.log(bst.findInorderPredecessor(bst.root, 7)); // 8
console.log(bst.findInorderPredecessor(bst.root, 12)); // null