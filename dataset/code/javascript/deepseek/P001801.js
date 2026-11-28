Here is the JavaScript code to convert a Binary Search Tree (BST) into a Sorted Doubly Linked List (DLL).

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
    const node = new Node(data);
    if (this.root === null) {
      this.root = node;
    } else {
      this.insertNode(this.root, node);
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
}

class NodeList {
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
    }
  }

  display() {
    let current = this.head;
    while (current !== null) {
      console.log(current.data);
      current = current.right;
    }
  }
}

function solve(n, lines) {
  const bst = new BST();
  const nodeList = new NodeList();

  for (let i = 0; i < n; i++) {
    bst.insert(lines[i]);
  }

  flattenBST(bst.root, nodeList);
  nodeList.display();
}

function flattenBST(node, list) {
  if (node === null) {
    return;
  }

  flattenBST(node.left, list);
  list.append(node.data);
  flattenBST(node.right, list);
}

// Input:
// 5
// 2
// 1
// 3
// 6
// 7
// Output:
// 1
// 2
// 3
// 6
// 7

In this code, we first create a BST and a NodeList. We then insert all the numbers from the input into the BST, and then use the BST and NodeList to flatten the BST into a sorted doubly linked list.