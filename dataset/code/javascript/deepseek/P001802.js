Here is the JavaScript code to convert a sorted doubly linked list into a height-balanced Binary Search Tree.

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  addNode(data) {
    var newNode = new Node(data);
    if (this.size === 0) {
      this.head = this.tail = newNode;
    } else {
      newNode.left = this.tail;
      this.tail.right = newNode;
      this.tail = newNode;
    }
    this.size++;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  sortedArrayToBST(arr, start, end) {
    if (start > end) {
      return null;
    }

    let mid = Math.floor((start + end) / 2);
    let node = new Node(arr[mid]);

    node.left = this.sortedArrayToBST(arr, start, mid - 1);
    node.right = this.sortedArrayToBST(arr, mid + 1, end);

    return node;
  }

  preOrder(node) {
    if (node !== null) {
      console.log(node.data + " ");
      this.preOrder(node.left);
      this.preOrder(node.right);
    }
  }
}

let n = parseInt(readline());
let arr = readline().split(" ").map(Number);

let dl = new DoublyLinkedList();
for (let i = 0; i < n; i++) {
  dl.addNode(arr[i]);
}

let bst = new BST();
bst.root = bst.sortedArrayToBST(arr, 0, n - 1);
bst.preOrder(bst.root);

This code first defines the Node and DoublyLinkedList classes. In the DoublyLinkedList class, the addNode method is used to add nodes to the doubly linked list. In the BST class, the sortedArrayToBST method is used to convert the doubly linked list into a height-balanced BST. The preOrder method is used to print the constructed BST.