Here is a JavaScript solution using recursive approach:

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  add(data) {
    const node = this.root;
    if (node === null) {
      this.root = new Node(data);
      return;
    } else {
      const searchTree = function(node) {
        if (data < node.data) {
          if (node.left === null) {
            node.left = new Node(data);
            return;
          } else if (node.left !== null) {
            return searchTree(node.left);
          }
        } else if (data > node.data) {
          if (node.right === null) {
            node.right = new Node(data);
            return;
          } else if (node.right !== null) {
            return searchTree(node.right);
          }
        } else {
          return null;
        }
      };
      return searchTree(node);
    }
  }

  inOrder() {
    if (this.root === null) {
      return null;
    } else {
      var res = [];
      function traverseInOrder(node) {
        node.left && traverseInOrder(node.left);
        res.push(node.data);
        node.right && traverseInOrder(node.right);
      }
      traverseInOrder(this.root);
      return res;
    }
  }

  unionBST(bst) {
    const thisInOrder = this.inOrder();
    const bstInOrder = bst.inOrder();
    const union = [...new Set([...thisInOrder, ...bstInOrder])];
    union.sort((a, b) => a - b);
    return union;
  }
}

const N = parseInt(readline());
const bst1 = new BST();
const bst2 = new BST();

for (let i = 0; i < N; i++) {
  const arr = readline().split(' ').map(Number);
  const data = arr[0];
  const left = arr[1];
  const right = arr[2];
  bst1.add(data);
}

for (let i = 0; i < N; i++) {
  const arr = readline().split(' ').map(Number);
  const data = arr[0];
  const left = arr[1];
  const right = arr[2];
  bst2.add(data);
}

const union = bst1.unionBST(bst2);
console.log(union.join(' '));

In this solution, we first define a `BST` class with methods to add nodes to the tree and to traverse the tree in-order. Then we create a `BST` for both input trees and call the `unionBST` method to find the union of the two trees.