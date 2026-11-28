Here is the JavaScript code to construct a binary tree from preorder and postorder traversals.

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

  createTree(preOrder, postOrder) {
    if (!postOrder.length) return null;

    let node = new Node(postOrder.pop());

    if (!postOrder.length) return node;

    let index = preOrder.indexOf(node.data);

    node.right = this.createTree(preOrder.slice(index + 1), postOrder);
    node.left = this.createTree(preOrder.slice(0, index), postOrder);

    return node;
  }

  preOrder(node) {
    if (node) {
      console.log(node.data + ' ');
      this.preOrder(node.left);
      this.preOrder(node.right);
    }
  }

  postOrder(node) {
    if (node) {
      this.postOrder(node.left);
      this.postOrder(node.right);
      console.log(node.data + ' ');
    }
  }
}

let tree = new BinaryTree();
let preOrder = 'ABDECF';
let postOrder = 'DBEACF';
console.log('Preorder: ' + preOrder);
console.log('Postorder: ' + postOrder);
tree.root = tree.createTree(preOrder.split(' '), postOrder.split(' '));
console.log('Reconstructed Tree:');
tree.postOrder(tree.root);
In this code, we define a class `Node` for creating new nodes, and another class `BinaryTree` for constructing the tree. The `createTree` function is used to construct the tree from the preorder and postorder traversals. If the postorder list is empty, it means we have reached a leaf node and we return null. Otherwise, we pop the last element from the postorder list and make it the root. Then, we find the root in the preorder list. After finding the root, we recursively create the left and right subtrees from the preorder list.

We then create an instance of `BinaryTree` and use it to create the tree from the given preorder and postorder traversals. Finally, we print the reconstructed tree in postorder traversal format.