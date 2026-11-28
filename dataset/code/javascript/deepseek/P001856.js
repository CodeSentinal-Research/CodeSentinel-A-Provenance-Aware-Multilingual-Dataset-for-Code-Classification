Sure, here is the JavaScript code to solve the problem. This code uses in-order traversal of the BST to build the doubly linked list.

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
  }

  append(data) {
    const newNode = new Node(data);
    if (this.head === null) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.right = newNode;
      newNode.left = this.tail;
      this.tail = newNode;
      this.tail.right = this.head;
      this.head.left = this.tail;
    }
  }

  display() {
    let start = this.head;
    let finish = this.tail;
    let result = "";
    do {
      result += start.data + " ";
      start = start.right;
    } while (start !== finish);
    console.log(result);
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  insert(data) {
    const newNode = new Node(data);
    if (this.root === null) {
      this.root = newNode;
    } else {
      this.insertNode(this.root, newNode);
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

  inOrder() {
    if (this.root === null) {
      return;
    } else {
      let list = new DoublyLinkedList();
      this.inOrderNode(this.root, list);
      list.display();
    }
  }

  inOrderNode(node, list) {
    if (node.left !== null) {
      this.inOrderNode(node.left, list);
    }
    list.append(node.data);
    if (node.right !== null) {
      this.inOrderNode(node.right, list);
    }
  }
}

// input
let n = 4;
let input = [5, 3, 8, 2];
input.forEach(i => {
  let bst = new BST();
  bst.insert(i);
  bst.inOrder();
});

In the above code, the `BST` class represents the Binary Search Tree and the `DoublyLinkedList` class represents the circular doubly linked list. The `insert` method is used to insert nodes into the BST and the `inOrder` method is used to convert the BST into a sorted circular doubly linked list.